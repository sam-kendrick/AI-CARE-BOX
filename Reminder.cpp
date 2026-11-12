#include "Reminder.h"
#include <iostream>

// Default constructor initializes default values
Reminder::Reminder() {
    title = "";
    time = "";
    isDone = false;
}

// Parameterized constructor
Reminder::Reminder(std::string reminderTitle, std::string reminderTime) {
    title = reminderTitle;
    time = reminderTime;
    isDone = false;
}

// Getter for title
std::string Reminder::getTitle() const {
    return title;
}

// Setter for title
void Reminder::setTitle(std::string newTitle) {
    title = newTitle;
}

// Getter for time
std::string Reminder::getTime() const {
    return time;
}

// Setter for time
void Reminder::setTime(std::string newTime) {
    time = newTime;
}

// Getter for completion status
bool Reminder::getIsDone() const {
    return isDone;
}

// Setter for completion status
void Reminder::setIsDone(bool status) {
    isDone = status;
}

// Mark the reminder as completed
void Reminder::markDone() {
    isDone = true;
}

// Print reminder details in clear format
void Reminder::show() const {
    std::cout << "[";
    if (isDone) {
        std::cout << "DONE";
    } else {
        std::cout << "PENDING";
    }
    std::cout << "] " << time << " - " << title << "\n";
}
