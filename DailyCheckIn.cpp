#include "DailyCheckIn.h"
#include <iostream>

// Default constructor
DailyCheckIn::DailyCheckIn() {
    checkedIn = false;
    isOkay = true;
    familyContact = NULL;
}

// Parameterized constructor
DailyCheckIn::DailyCheckIn(FamilyContact* contact) {
    checkedIn = false;
    isOkay = true;
    familyContact = contact;
}

// Getter for checkedIn
bool DailyCheckIn::getCheckedIn() const {
    return checkedIn;
}

// Setter for checkedIn
void DailyCheckIn::setCheckedIn(bool status) {
    checkedIn = status;
}

// Getter for isOkay
bool DailyCheckIn::getIsOkay() const {
    return isOkay;
}

// Setter for isOkay
void DailyCheckIn::setIsOkay(bool status) {
    isOkay = status;
}

// Setter for family contact pointer
void DailyCheckIn::setFamilyContact(FamilyContact* contact) {
    familyContact = contact;
}

// Getter for family contact pointer
FamilyContact* DailyCheckIn::getFamilyContact() const {
    return familyContact;
}

// Conduct daily check-in
void DailyCheckIn::performCheckIn() {
    std::cout << "\n============================================\n";
    std::cout << "          DAILY WELLBEING CHECK-IN\n";
    std::cout << "============================================\n";
    std::cout << "  Hello! This is your daily wellbeing check.\n\n";
    std::cout << "  >>> Are you feeling okay today? (yes / no): ";

    std::string response;
    std::cin >> response;

    // Convert response to lower case if first char is uppercase
    if (response == "yes" || response == "Yes" || response == "YES" || response == "y" || response == "Y") {
        checkedIn = true;
        isOkay = true;
        std::cout << "\n--------------------------------------------\n";
        std::cout << "  [+] WONDERFUL! So glad you are feeling good!\n";
        std::cout << "  Remember to stay hydrated and take walks.\n";
        std::cout << "--------------------------------------------\n";
    } else {
        checkedIn = true;
        isOkay = false;
        std::cout << "\n--------------------------------------------\n";
        std::cout << "  [!] We are sorry to hear you're not feeling well.\n";
        std::cout << "  Your health and safety come first!\n";
        std::cout << "--------------------------------------------\n";

        // Trigger alert to family contact
        if (familyContact != NULL) {
            familyContact->sendAlert("User reported feeling unwell during the daily wellbeing check-in. Please call or visit them.");
        } else {
            std::cout << "  [!] Notice: No emergency contact configured.\n";
        }
    }
}
