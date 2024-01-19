/***********************************************************************
// OOP244 Utils Module
// File    Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
using namespace std;

namespace sdds {
    // Function to get an integer within a specified range
    int getInteger(int min, int max) {
        int number;

        // Loop until a valid integer within the specified range is entered
        for (int i = 0;; i++) {
            cin >> number;

            // Check if the input is not an integer or is outside the specified range
            if (!cin || number < min || number > max) {
                cout << "Invalid Selection, try again: ";
                cin.clear();                    // Clear the error flag
                cin.ignore(1000, '\n');         // Discard invalid input
            }
            else {
                break;                          // Exit the loop if a valid input is received
            }
        }
        return number;
    }

}  // namespace sdds
