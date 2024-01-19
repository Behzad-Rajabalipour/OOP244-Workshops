#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Car.h"

namespace sdds {
    // Parameterized constructor
    Car::Car(const char* plate, const char* makeModel) {
        set(plate, makeModel);
    }

    // Setter function to set car information
    void Car::set(const char* plate, const char* makeModel) {
        // Copy the license plate (up to 8 characters)
        strncpy(m_plate, plate, 8);
        m_plate[8] = 0; // Ensure null-termination of the string

        // Copy the make/model (up to 40 characters)
        strncpy(m_makeModel, makeModel, 40);
        m_makeModel[40] = 0; // Ensure null-termination of the string
    }

    // Display function to show car information
    std::ostream& Car::display(std::ostream& os) const {
        return os << m_plate << " " << m_makeModel;
    }

    // Read function to read car information from input
    std::istream& Car::read(std::istream& is) {
        is >> m_plate;
        is.getline(m_makeModel, 40, '\n');
        return is;
    }

    // Operator overload to check if the car's make/model contains a given substring
    bool Car::operator==(const char* mmSubstr) const {
        // Use strstr to check if mmSubstr is present in m_makeModel
        // If it is, strstr returns a non-null pointer, indicating a match
        return strstr(m_makeModel, mmSubstr) != nullptr;
    }
}
