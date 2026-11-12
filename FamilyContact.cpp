#include "FamilyContact.h"
#include <iostream>

// Default constructor
FamilyContact::FamilyContact() {
    name = "Family Member";
    phone = "Not Set";
    relation = "Family";
}

// Parameterized constructor
FamilyContact::FamilyContact(std::string contactName, std::string contactPhone, std::string contactRelation) {
    name = contactName;
    phone = contactPhone;
    relation = contactRelation;
}

// Getter for name
std::string FamilyContact::getName() const {
    return name;
}

// Setter for name
void FamilyContact::setName(std::string contactName) {
    name = contactName;
}

// Getter for phone
std::string FamilyContact::getPhone() const {
    return phone;
}

// Setter for phone
void FamilyContact::setPhone(std::string contactPhone) {
    phone = contactPhone;
}

// Getter for relation
std::string FamilyContact::getRelation() const {
    return relation;
}

// Setter for relation
void FamilyContact::setRelation(std::string contactRelation) {
    relation = contactRelation;
}

// Display contact details clearly
void FamilyContact::showContact() const {
    std::cout << "\n============================================\n";
    std::cout << "             FAMILY CONTACT\n";
    std::cout << "============================================\n";
    std::cout << "  Name:     " << name << "\n";
    std::cout << "  Relation: " << relation << "\n";
    std::cout << "  Phone:    " << phone << "\n";
    std::cout << "============================================\n";
}

// Simulate sending an alert notification
void FamilyContact::sendAlert(std::string message) const {
    std::cout << "\n************************************************************\n";
    std::cout << "             !!! EMERGENCY ALERT SENT !!!\n";
    std::cout << "************************************************************\n";
    std::cout << "  Dispatching alert to: " << name << " (" << relation << ")\n";
    std::cout << "  Contact Number:       " << phone << "\n";
    std::cout << "  Alert Message:        \"" << message << "\"\n";
    std::cout << "  Status:               Notification delivered successfully.\n";
    std::cout << "************************************************************\n";
}
