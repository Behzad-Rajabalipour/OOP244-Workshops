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

// Including necessary header files
#include <iostream>
#include "Utils.h"

// Using the standard C++ namespace
using namespace std;

namespace sdds {
    // Function to get an integer within a specified range
    int getInteger(int min, int max) {
        int number;

        // Loop until a valid integer within the specified range is entered
        for (int i = 0;; i++) {
            // Read the integer from the standard input
            cin >> number;

            // Check if input is not a valid integer or outside the specified range
            if (!cin || number < min || number > max) {
                // Display error message and clear input buffer
                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                // Break the loop if a valid integer is entered
                break;
            }
        }

        // Return the valid integer
        return number;
    }

} // namespace sdds
