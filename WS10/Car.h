/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "ReadWrite.h"

namespace sdds {
    class Car : public ReadWrite {
        char m_plate[9];           // License plate of the car (up to 8 characters)
        char m_makeModel[41];      // Make and model of the car (up to 40 characters)
    public:
        // Constructor with optional parameters for license plate and make/model
        Car(const char* plate = "", const char* makeModel = "");

        // Set the license plate and make/model of the car
        void set(const char* plate, const char* makeModel);

        // Display the car's information
        std::ostream& display(std::ostream& os) const;

        // Read the car's information from input
        std::istream& read(std::istream& is);

        // Check if the make/model contains the specified substring
        bool operator==(const char* mmSubstr) const;
    };
}
#endif // !SDDS_CAR_H_
