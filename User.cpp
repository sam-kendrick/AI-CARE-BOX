#include "User.h"
#include <iostream>

// Default constructor
User::User() {
    name = "Default User";
    age = 0;
    language = "English";
}

// Parameterized constructor
User::User(std::string userName, int userAge, std::string userLanguage) {
    name = userName;
    age = userAge;
    language = userLanguage;
}

// Virtual destructor
User::~User() {
    // Empty virtual destructor
}

// Getter for name
std::string User::getName() const {
    return name;
}

// Setter for name
void User::setName(std::string userName) {
    name = userName;
}

// Getter for age
int User::getAge() const {
    return age;
}

// Setter for age
void User::setAge(int userAge) {
    age = userAge;
}

// Getter for language
std::string User::getLanguage() const {
    return language;
}

// Setter for language
void User::setLanguage(std::string userLanguage) {
    language = userLanguage;
}

// Display basic profile
void User::showProfile() const {
    std::cout << "\n============================================\n";
    std::cout << "                USER PROFILE\n";
    std::cout << "============================================\n";
    std::cout << "  Name:     " << name << "\n";
    std::cout << "  Age:      " << age << "\n";
    std::cout << "  Language: " << language << "\n";
    std::cout << "  Role:     " << getUserType() << "\n";
}

// Default implementation for tasks or medicines
void User::showTasksOrMedicines() const {
    std::cout << "  No tasks or medicines scheduled.\n";
}

// Default user type
std::string User::getUserType() const {
    return "Standard User";
}
