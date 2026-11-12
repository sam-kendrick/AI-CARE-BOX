#pragma once
#include <string>

// Reminder represents a single scheduled item or notification
class Reminder {
private:
    std::string title;
    std::string time;
    bool isDone;

public:
    // Default constructor
    Reminder();

    // Parameterized constructor
    Reminder(std::string reminderTitle, std::string reminderTime);

    // Getters and setters
    std::string getTitle() const;
    void setTitle(std::string newTitle);

    std::string getTime() const;
    void setTime(std::string newTime);

    bool getIsDone() const;
    void setIsDone(bool status);

    // Business methods
    void markDone();
    void show() const;
};
