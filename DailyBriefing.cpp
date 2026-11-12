#include "DailyBriefing.h"
#include <iostream>

// Default constructor
DailyBriefing::DailyBriefing() {
    user = NULL;
    reminderManager = NULL;
}

// Parameterized constructor
DailyBriefing::DailyBriefing(User* currentUser, ReminderManager* currentReminders) {
    user = currentUser;
    reminderManager = currentReminders;
}

// Setter for user
void DailyBriefing::setUser(User* currentUser) {
    user = currentUser;
}

// Getter for user
User* DailyBriefing::getUser() const {
    return user;
}

// Setter for reminder manager
void DailyBriefing::setReminderManager(ReminderManager* currentReminders) {
    reminderManager = currentReminders;
}

// Getter for reminder manager
ReminderManager* DailyBriefing::getReminderManager() const {
    return reminderManager;
}

// Print daily briefing
void DailyBriefing::showBriefing() const {
    std::cout << "\n============================================\n";
    std::cout << "        *** AI CARE BOX DAILY BRIEFING ***\n";
    std::cout << "============================================\n";

    if (user != NULL) {
        std::cout << "  Good day, " << user->getName() << "!\n";
        std::cout << "  Preferred Language: " << user->getLanguage() << "\n";
        std::cout << "  User Role:          " << user->getUserType() << "\n";
    } else {
        std::cout << "  Good day! Welcome to your morning briefing.\n";
    }

    std::cout << "\n  --- [1] TODAY'S PENDING REMINDERS ---";
    if (reminderManager != NULL) {
        reminderManager->listPending();
    } else {
        std::cout << "\n  No reminder service attached.\n";
    }

    std::cout << "\n  --- [2] TODAY'S SCHEDULED ITEMS ---";
    if (user != NULL) {
        user->showTasksOrMedicines();
    } else {
        std::cout << "\n  No user schedule available.\n";
    }

    std::cout << "\n============================================\n";
    std::cout << "  Tip: Take breaks, stay safe, and smile today!\n";
    std::cout << "============================================\n";
}
