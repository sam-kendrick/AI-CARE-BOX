#pragma once
#include <string>

// FamilyContact stores contact info for trusted family members or caregivers
class FamilyContact {
private:
    std::string name;
    std::string phone;
    std::string relation;

public:
    // Default constructor
    FamilyContact();

    // Parameterized constructor
    FamilyContact(std::string contactName, std::string contactPhone, std::string contactRelation);

    // Getters and setters
    std::string getName() const;
    void setName(std::string contactName);

    std::string getPhone() const;
    void setPhone(std::string contactPhone);

    std::string getRelation() const;
    void setRelation(std::string contactRelation);

    // Display contact information
    void showContact() const;

    // Simulate sending an emergency alert via SMS/Call
    void sendAlert(std::string message) const;
};
