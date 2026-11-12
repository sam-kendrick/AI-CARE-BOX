#pragma once
#include <string>

// User is the base class for both Elderly and Professional users
class User {
private:
    std::string name;
    int age;
    std::string language;

public:
    // Default constructor
    User();

    // Parameterized constructor
    User(std::string userName, int userAge, std::string userLanguage);

    // Virtual destructor for proper inheritance cleanup
    virtual ~User();

    // Getters and setters
    std::string getName() const;
    void setName(std::string userName);

    int getAge() const;
    void setAge(int userAge);

    std::string getLanguage() const;
    void setLanguage(std::string userLanguage);

    // Displays common profile information
    virtual void showProfile() const;

    // Virtual helper to display user-specific daily schedule (medicines or work tasks)
    virtual void showTasksOrMedicines() const;

    // Virtual helper to identify user type
    virtual std::string getUserType() const;
};
