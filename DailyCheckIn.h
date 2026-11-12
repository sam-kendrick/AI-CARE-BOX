#pragma once
#include "FamilyContact.h"
#include <string>

// DailyCheckIn manages daily wellbeing verification and automated safety alerts
class DailyCheckIn {
private:
    bool checkedIn;
    bool isOkay;
    FamilyContact* familyContact;

public:
    // Default constructor
    DailyCheckIn();

    // Parameterized constructor with FamilyContact reference
    DailyCheckIn(FamilyContact* contact);

    // Getters and setters
    bool getCheckedIn() const;
    void setCheckedIn(bool status);

    bool getIsOkay() const;
    void setIsOkay(bool status);

    void setFamilyContact(FamilyContact* contact);
    FamilyContact* getFamilyContact() const;

    // Asks the user if they are okay, stores response, and sends alert if not okay
    void performCheckIn();
};
