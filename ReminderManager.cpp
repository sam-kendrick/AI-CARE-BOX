#include "ReminderManager.h"
#include <iostream>

// Constructor initializes empty list
ReminderManager::ReminderManager() {
    count = 0;
}

// Add a new reminder to the fixed array
bool ReminderManager::addReminder(std::string title, std::string time, bool verbose) {
    if (count >= MAX_REMINDERS) {
        if (verbose) {
            std::cout << "\n[!] Reminder list is full! Cannot add more.\n";
        }
        return false;
    }
    reminders[count] = Reminder(title, time);
    count++;
    if (verbose) {
        std::cout << "\n============================================\n";
        std::cout << "  (+) REMINDER ADDED SUCCESSFULLY!\n";
        std::cout << "  \"" << title << "\" at " << time << "\n";
        std::cout << "============================================\n";
    }
    return true;
}

// Display all reminders in a neat table format
void ReminderManager::listReminders() const {
    std::cout << "\n============================================\n";
    std::cout << "             ALL REMINDERS\n";
    std::cout << "============================================\n";
    if (count == 0) {
        std::cout << "  No reminders set yet.\n";
        std::cout << "============================================\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        std::cout << "  " << (i + 1) << ". ";
        reminders[i].show();
    }
    std::cout << "============================================\n";
}

// Mark reminder as done using 1-based index
bool ReminderManager::completeReminder(int index) {
    // Check if index is valid (1-based for friendly human input)
    if (index < 1 || index > count) {
        std::cout << "\n[!] Invalid reminder number: " << index << "\n";
        return false;
    }

    int zeroIndex = index - 1;
    if (reminders[zeroIndex].getIsDone()) {
        std::cout << "\n[*] That reminder is already completed!\n";
        return true;
    }

    reminders[zeroIndex].markDone();
    std::cout << "\n============================================\n";
    std::cout << "  [V] REMINDER COMPLETED!\n";
    std::cout << "  \"" << reminders[zeroIndex].getTitle() << "\"\n";
    std::cout << "============================================\n";
    return true;
}

// List only unfinished reminders
void ReminderManager::listPending() const {
    std::cout << "\n============================================\n";
    std::cout << "            PENDING REMINDERS\n";
    std::cout << "============================================\n";
    int pendingCount = 0;
    for (int i = 0; i < count; i++) {
        if (!reminders[i].getIsDone()) {
            std::cout << "  " << (i + 1) << ". ";
            reminders[i].show();
            pendingCount++;
        }
    }
    if (pendingCount == 0) {
        std::cout << "  Great job! You have no pending reminders.\n";
    }
    std::cout << "============================================\n";
}

// Get total count
int ReminderManager::getCount() const {
    return count;
}

// Get pending count
int ReminderManager::getPendingCount() const {
    int pendingCount = 0;
    for (int i = 0; i < count; i++) {
        if (!reminders[i].getIsDone()) {
            pendingCount++;
        }
    }
    return pendingCount;
}
