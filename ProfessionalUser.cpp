#include "ProfessionalUser.h"
#include <iostream>

// Default constructor
ProfessionalUser::ProfessionalUser() : User("Professional User", 30, "English") {
    jobTitle = "Working Professional";
    workHours = "9:00 AM - 5:00 PM";
    taskCount = 0;
}

// Parameterized constructor
ProfessionalUser::ProfessionalUser(std::string userName, int userAge, std::string userLanguage,
                                   std::string title, std::string hours)
    : User(userName, userAge, userLanguage) {
    jobTitle = title;
    workHours = hours;
    taskCount = 0;
}

// Getter for job title
std::string ProfessionalUser::getJobTitle() const {
    return jobTitle;
}

// Setter for job title
void ProfessionalUser::setJobTitle(std::string title) {
    jobTitle = title;
}

// Getter for work hours
std::string ProfessionalUser::getWorkHours() const {
    return workHours;
}

// Setter for work hours
void ProfessionalUser::setWorkHours(std::string hours) {
    workHours = hours;
}

// Getter for task count
int ProfessionalUser::getTaskCount() const {
    return taskCount;
}

// Getter for specific task by index
std::string ProfessionalUser::getTask(int index) const {
    if (index >= 0 && index < taskCount) {
        return taskList[index];
    }
    return "";
}

// Add a work task
bool ProfessionalUser::addTask(std::string task) {
    if (taskCount >= MAX_TASKS) {
        std::cout << "\n[!] Task list is full!\n";
        return false;
    }
    taskList[taskCount] = task;
    taskCount++;
    std::cout << "\n  (+) Added work task: " << task << "\n";
    return true;
}

// Display all work tasks
void ProfessionalUser::showTasks() const {
    std::cout << "\n============================================\n";
    std::cout << "           TODAY'S WORK TASKS\n";
    std::cout << "============================================\n";
    if (taskCount == 0) {
        std::cout << "  No tasks scheduled.\n";
    } else {
        for (int i = 0; i < taskCount; i++) {
            std::cout << "  " << (i + 1) << ". " << taskList[i] << "\n";
        }
    }
    std::cout << "============================================\n";
}

// Override showProfile
void ProfessionalUser::showProfile() const {
    User::showProfile();
    std::cout << "  Job Title: " << jobTitle << "\n";
    std::cout << "  Hours:     " << workHours << "\n";
    std::cout << "  Tasks:     " << taskCount << " logged\n";
    std::cout << "============================================\n";
    showTasks();
}

// Override showTasksOrMedicines to present work tasks
void ProfessionalUser::showTasksOrMedicines() const {
    showTasks();
}

// User type string
std::string ProfessionalUser::getUserType() const {
    return "Working Professional";
}
