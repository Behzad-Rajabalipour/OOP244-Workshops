/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include <iostream>
#include "Utils.h"
using namespace std;

namespace sdds {
	// Function to get an integer within the specified range [min, max]
	int getInteger(int min, int max) {
		int number;
		for (int i = 0;; i++) {
			cin >> number;
			if (!cin || number < min || number > max) { // Check if input is not an integer or out of range
				cout << "Invalid Selection, try again: ";
				cin.clear(); // Clear any error flags in the input stream
				cin.ignore(1000, '\n'); // Ignore any remaining characters in the input stream
			}
			else {
				break; // Valid input, exit the loop
			}
		}
		return number; // Return the valid integer
	}
}
