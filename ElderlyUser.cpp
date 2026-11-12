#include "ElderlyUser.h"
#include <iostream>

// Default constructor
ElderlyUser::ElderlyUser() : User("Senior User", 75, "English") {
    emergencyContact = "Not Set";
    medicineCount = 0;
}

// Parameterized constructor
ElderlyUser::ElderlyUser(std::string userName, int userAge, std::string userLanguage, std::string userEmergencyContact)
    : User(userName, userAge, userLanguage) {
    emergencyContact = userEmergencyContact;
    medicineCount = 0;
}

// Getter for emergency contact
std::string ElderlyUser::getEmergencyContact() const {
    return emergencyContact;
}

// Setter for emergency contact
void ElderlyUser::setEmergencyContact(std::string contact) {
    emergencyContact = contact;
}

// Getter for medicine count
int ElderlyUser::getMedicineCount() const {
    return medicineCount;
}

// Getter for a specific medicine by index
std::string ElderlyUser::getMedicine(int index) const {
    if (index >= 0 && index < medicineCount) {
        return medicineList[index];
    }
    return "";
}

// Add a medicine
bool ElderlyUser::addMedicine(std::string medicine) {
    if (medicineCount >= MAX_MEDICINES) {
        std::cout << "\n[!] Medicine list is full!\n";
        return false;
    }
    medicineList[medicineCount] = medicine;
    medicineCount++;
    std::cout << "\n  (+) Added medicine: " << medicine << "\n";
    return true;
}

// Display all registered medicines
void ElderlyUser::showMedicines() const {
    std::cout << "\n============================================\n";
    std::cout << "           DAILY MEDICINE SCHEDULE\n";
    std::cout << "============================================\n";
    if (medicineCount == 0) {
        std::cout << "  No medicines listed.\n";
    } else {
        for (int i = 0; i < medicineCount; i++) {
            std::cout << "  " << (i + 1) << ". " << medicineList[i] << "\n";
        }
    }
    std::cout << "============================================\n";
}

// Override showProfile to include elderly-specific details
void ElderlyUser::showProfile() const {
    User::showProfile();
    std::cout << "  Emergency: " << emergencyContact << "\n";
    std::cout << "  Medicines: " << medicineCount << " registered\n";
    std::cout << "============================================\n";
    showMedicines();
}

// Override showTasksOrMedicines to present medicine schedule
void ElderlyUser::showTasksOrMedicines() const {
    showMedicines();
}

// User type string
std::string ElderlyUser::getUserType() const {
    return "Elderly Senior";
}
