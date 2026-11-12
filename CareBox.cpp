#include "CareBox.h"
#include <iostream>

// Constructor initializes subsystems and links pointers
CareBox::CareBox() {
    user = NULL;
    isRunning = true;

    // Default emergency family contact
    familyContact = FamilyContact("Sarah Johnson", "+1-555-0192", "Daughter");

    // Link contact to daily check-in
    dailyCheckIn.setFamilyContact(&familyContact);

    // Populate initial starter reminders quietly
    reminderManager.addReminder("Morning Blood Pressure Pill", "08:00 AM", false);
    reminderManager.addReminder("Drink 2 Glasses of Fresh Water", "11:30 AM", false);
    reminderManager.addReminder("Afternoon Walk & Stretch", "04:30 PM", false);

    // Configure voice assistant
    voiceAssistant.setAssistantName("Aura");
}

// Destructor cleans up dynamically allocated User
CareBox::~CareBox() {
    if (user != NULL) {
        delete user;
        user = NULL;
    }
}

// Clear leftover characters in the standard input buffer
void CareBox::clearInputBuffer() {
    std::string leftover;
    std::getline(std::cin, leftover);
}

// Getter for User pointer
User* CareBox::getUser() const {
    return user;
}

// Setter for User pointer
void CareBox::setUser(User* newUser) {
    if (user != NULL) {
        delete user;
    }
    user = newUser;
    dailyBriefing.setUser(user);
}

// Getter for ReminderManager
ReminderManager& CareBox::getReminderManager() {
    return reminderManager;
}

// Getter for FamilyContact
FamilyContact& CareBox::getFamilyContact() {
    return familyContact;
}

// Getter for DailyCheckIn
DailyCheckIn& CareBox::getDailyCheckIn() {
    return dailyCheckIn;
}

// Getter for DailyBriefing
DailyBriefing& CareBox::getDailyBriefing() {
    return dailyBriefing;
}

// Getter for VoiceAssistant
VoiceAssistant& CareBox::getVoiceAssistant() {
    return voiceAssistant;
}

// Display welcome banner
void CareBox::displayBanner() const {
    std::cout << "\n";
    std::cout << "############################################################\n";
    std::cout << "#                                                          #\n";
    std::cout << "#                      AI CARE BOX                         #\n";
    std::cout << "#            Personal Care & Productivity System           #\n";
    std::cout << "#                                                          #\n";
    std::cout << "############################################################\n";
}

// Display main menu with large clear text suitable for all ages
void CareBox::displayMenu() const {
    std::cout << "\n============================================\n";
    std::cout << "                 MAIN MENU\n";
    std::cout << "============================================\n";
    std::cout << "  [1] Talk to assistant\n";
    std::cout << "  [2] Add reminder\n";
    std::cout << "  [3] View reminders\n";
    std::cout << "  [4] Mark reminder done\n";
    std::cout << "  [5] Daily check-in\n";
    std::cout << "  [6] Daily briefing\n";
    std::cout << "  [7] Call family (simulated)\n";
    std::cout << "  [0] Exit\n";
    std::cout << "============================================\n";
    std::cout << "  Please enter a number (0 - 7): ";
}

// Setup user profile on startup
void CareBox::setupProfile() {
    displayBanner();
    std::cout << "\n  Welcome! Please select the user profile type:\n";
    std::cout << "  1. Senior / Elderly Citizen\n";
    std::cout << "  2. Busy Working Professional\n";
    std::cout << "  Enter choice (1 or 2): ";

    int profileChoice = 1;
    if (!(std::cin >> profileChoice)) {
        std::cin.clear();
        clearInputBuffer();
        profileChoice = 1;
    } else {
        clearInputBuffer();
    }

    if (profileChoice == 2) {
        std::cout << "\n  Setting up Working Professional Profile...\n";
        std::cout << "  Enter Name (or press Enter for 'Alex'): ";
        std::string name;
        std::getline(std::cin, name);
        if (name.empty()) name = "Alex Chen";

        ProfessionalUser* prof = new ProfessionalUser(name, 34, "English", "Software Engineer", "9:00 AM - 6:00 PM");
        prof->addTask("Review pull request #104");
        prof->addTask("Team sync call at 2:00 PM");
        prof->addTask("Complete sprint documentation");

        setUser(prof);
    } else {
        std::cout << "\n  Setting up Elderly Senior Profile...\n";
        std::cout << "  Enter Name (or press Enter for 'Martha'): ";
        std::string name;
        std::getline(std::cin, name);
        if (name.empty()) name = "Martha Stewart";

        ElderlyUser* elderly = new ElderlyUser(name, 78, "English", "Sarah Johnson (555-0192)");
        elderly->addMedicine("Blood Pressure Tablet - 1 pill morning");
        elderly->addMedicine("Calcium & Vitamin D - 1 pill noon");
        elderly->addMedicine("Heart Medication - 1 pill evening");

        setUser(elderly);
    }

    // Attach user and reminder manager to daily briefing
    dailyBriefing.setUser(user);
    dailyBriefing.setReminderManager(&reminderManager);

    std::cout << "\n============================================\n";
    std::cout << "  [+] PROFILE CONFIGURED SUCCESSFULLY!\n";
    if (user != NULL) {
        std::cout << "  Welcome, " << user->getName() << "!\n";
    }
    std::cout << "============================================\n";
}

// Handler for Option 1: Talk to assistant
void CareBox::handleVoiceAssistant() {
    std::string query = voiceAssistant.listen();
    voiceAssistant.respond(query);
}

// Handler for Option 2: Add reminder
void CareBox::handleAddReminder() {
    std::cout << "\n============================================\n";
    std::cout << "             CREATE NEW REMINDER\n";
    std::cout << "============================================\n";
    std::cout << "  Enter reminder title (e.g., Take medication): ";
    std::string title;
    std::getline(std::cin, title);

    if (title.empty()) {
        std::cout << "  [!] Reminder title cannot be empty.\n";
        return;
    }

    std::cout << "  Enter reminder time (e.g., 03:00 PM): ";
    std::string time;
    std::getline(std::cin, time);

    if (time.empty()) {
        time = "Today";
    }

    reminderManager.addReminder(title, time);
}

// Handler for Option 3: View reminders
void CareBox::handleViewReminders() {
    reminderManager.listReminders();
}

// Handler for Option 4: Mark reminder done
void CareBox::handleMarkReminderDone() {
    reminderManager.listReminders();
    if (reminderManager.getCount() == 0) {
        return;
    }

    std::cout << "\n  Enter the reminder number to mark as completed: ";
    int index = 0;
    if (!(std::cin >> index)) {
        std::cin.clear();
        clearInputBuffer();
        std::cout << "  [!] Invalid input. Please enter a valid number.\n";
        return;
    }
    clearInputBuffer();

    reminderManager.completeReminder(index);
}

// Handler for Option 5: Daily check-in
void CareBox::handleDailyCheckIn() {
    dailyCheckIn.performCheckIn();
}

// Handler for Option 6: Daily briefing
void CareBox::handleDailyBriefing() {
    dailyBriefing.showBriefing();
}

// Handler for Option 7: Call family (simulated)
void CareBox::handleCallFamily() {
    std::cout << "\n============================================\n";
    std::cout << "        SIMULATED VOICE CALL TO FAMILY\n";
    std::cout << "============================================\n";
    std::cout << "  Contact: " << familyContact.getName() << " (" << familyContact.getRelation() << ")\n";
    std::cout << "  Phone:   " << familyContact.getPhone() << "\n\n";
    std::cout << "  [Connecting to phone network...] \n";
    std::cout << "  * Ring... Ring... *\n";
    std::cout << "  >>> [CALL CONNECTED]\n\n";
    std::cout << "  " << familyContact.getName() << ": \"Hello! So wonderful to hear your voice.\n";
    std::cout << "  How are you feeling today?\"\n\n";
    std::cout << "  AI Care Box: Audio link stable. Call completed successfully.\n";
    std::cout << "============================================\n";
}

// Main execution loop
void CareBox::run() {
    setupProfile();

    while (isRunning) {
        displayMenu();

        int choice = -1;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            clearInputBuffer();
            std::cout << "\n[!] Please enter a valid number from the menu.\n";
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                handleVoiceAssistant();
                break;
            case 2:
                handleAddReminder();
                break;
            case 3:
                handleViewReminders();
                break;
            case 4:
                handleMarkReminderDone();
                break;
            case 5:
                handleDailyCheckIn();
                break;
            case 6:
                handleDailyBriefing();
                break;
            case 7:
                handleCallFamily();
                break;
            case 0:
                isRunning = false;
                std::cout << "\n============================================\n";
                std::cout << "  Thank you for using AI Care Box!\n";
                std::cout << "  Wishing you good health and a peaceful day.\n";
                std::cout << "  Goodbye!\n";
                std::cout << "============================================\n\n";
                break;
            default:
                std::cout << "\n[!] Option " << choice << " is not recognized. Please choose between 0 and 7.\n";
                break;
        }
    }
}
