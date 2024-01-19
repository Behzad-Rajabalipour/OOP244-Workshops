#include <iostream>
#include "Utils.h"
using namespace std;

namespace sdds {
	// Function to get an integer within a specified range
	int getInteger(int min, int max) {
		int number;
		for (int i = 0;; i++) {
			cin >> number;
			if (!cin || number < min || number > max) { // Check if input is not an integer or outside the specified range
				cout << "Invalid Selection, try again: ";
				cin.clear(); // Clear any error flags set by previous invalid input
				cin.ignore(1000, '\n'); // Ignore any characters remaining in the input buffer, up to a newline character
			}
			else {
				break; // Input is valid, exit the loop
			}
		}
		return number; // Return the valid integer
	}
}
