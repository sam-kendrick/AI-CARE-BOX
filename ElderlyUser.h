#pragma once
#include "User.h"
#include <string>

// ElderlyUser represents a senior citizen needing medicine and safety tracking
class ElderlyUser : public User {
private:
    static const int MAX_MEDICINES = 20;
    std::string emergencyContact;
    std::string medicineList[MAX_MEDICINES];
    int medicineCount;

public:
    // Default constructor
    ElderlyUser();

    // Parameterized constructor
    ElderlyUser(std::string userName, int userAge, std::string userLanguage, std::string userEmergencyContact);

    // Getters and setters
    std::string getEmergencyContact() const;
    void setEmergencyContact(std::string contact);

    int getMedicineCount() const;
    std::string getMedicine(int index) const;

    // Add a medicine to the medicine list
    bool addMedicine(std::string medicine);

    // Display all medicines
    void showMedicines() const;

    // Override base class showProfile
    void showProfile() const;

    // Override showTasksOrMedicines to display medicines
    void showTasksOrMedicines() const;

    // Return role description
    std::string getUserType() const;
};
