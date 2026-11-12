#pragma once
#include "User.h"
#include "ReminderManager.h"

// DailyBriefing aggregates daily overview including greeting, pending reminders, and scheduled tasks/medicines
class DailyBriefing {
private:
    User* user;
    ReminderManager* reminderManager;

public:
    // Default constructor
    DailyBriefing();

    // Parameterized constructor
    DailyBriefing(User* currentUser, ReminderManager* currentReminders);

    // Getters and setters
    void setUser(User* currentUser);
    User* getUser() const;

    void setReminderManager(ReminderManager* currentReminders);
    ReminderManager* getReminderManager() const;

    // Print morning/daily briefing
    void showBriefing() const;
};
