#pragma once
#include "User.h"
#include <string>

// ProfessionalUser represents a busy professional managing tasks and work schedule
class ProfessionalUser : public User {
private:
    static const int MAX_TASKS = 20;
    std::string jobTitle;
    std::string workHours;
    std::string taskList[MAX_TASKS];
    int taskCount;

public:
    // Default constructor
    ProfessionalUser();

    // Parameterized constructor
    ProfessionalUser(std::string userName, int userAge, std::string userLanguage,
                     std::string title, std::string hours);

    // Getters and setters
    std::string getJobTitle() const;
    void setJobTitle(std::string title);

    std::string getWorkHours() const;
    void setWorkHours(std::string hours);

    int getTaskCount() const;
    std::string getTask(int index) const;

    // Add a professional task
    bool addTask(std::string task);

    // Display all tasks
    void showTasks() const;

    // Override base class showProfile
    void showProfile() const;

    // Override showTasksOrMedicines to display work tasks
    void showTasksOrMedicines() const;

    // Return role description
    std::string getUserType() const;
};
