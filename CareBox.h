#pragma once
#include "User.h"
#include "ElderlyUser.h"
#include "ProfessionalUser.h"
#include "ReminderManager.h"
#include "FamilyContact.h"
#include "DailyCheckIn.h"
#include "DailyBriefing.h"
#include "VoiceAssistant.h"

// CareBox is the central controller coordinating all subsystems and user interaction
class CareBox {
private:
    User* user;
    ReminderManager reminderManager;
    FamilyContact familyContact;
    DailyCheckIn dailyCheckIn;
    DailyBriefing dailyBriefing;
    VoiceAssistant voiceAssistant;
    bool isRunning;

    // Helper methods for menu handling
    void displayBanner() const;
    void displayMenu() const;
    void setupProfile();
    void clearInputBuffer();

    // Menu action handlers
    void handleVoiceAssistant();
    void handleAddReminder();
    void handleViewReminders();
    void handleMarkReminderDone();
    void handleDailyCheckIn();
    void handleDailyBriefing();
    void handleCallFamily();

public:
    // Constructor
    CareBox();

    // Destructor
    ~CareBox();

    // Getters and setters
    User* getUser() const;
    void setUser(User* newUser);

    ReminderManager& getReminderManager();
    FamilyContact& getFamilyContact();
    DailyCheckIn& getDailyCheckIn();
    DailyBriefing& getDailyBriefing();
    VoiceAssistant& getVoiceAssistant();

    // Main execution loop
    void run();
};
