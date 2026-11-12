#pragma once
#include "Reminder.h"
#include <string>

// ReminderManager manages a fixed-size collection of reminders
class ReminderManager {
private:
    static const int MAX_REMINDERS = 50;
    Reminder reminders[MAX_REMINDERS];
    int count;

public:
    // Constructor
    ReminderManager();

    // Add a reminder with title and time
    bool addReminder(std::string title, std::string time, bool verbose = true);

    // List all reminders
    void listReminders() const;

    // Mark a specific reminder as completed by 1-based index
    bool completeReminder(int index);

    // List only reminders that are not done yet
    void listPending() const;

    // Get count of total reminders
    int getCount() const;

    // Get count of pending reminders
    int getPendingCount() const;
};
