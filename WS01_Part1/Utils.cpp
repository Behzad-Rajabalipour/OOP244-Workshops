#include <iostream>
#include "Utils.h" // Include the Utils header file

using namespace std;

namespace sdds { // Start of namespace sdds

    void flushkeys() {
        while (cin.get() != '\n'); // Keep reading characters until a newline is encountered
    }

    bool ValidYesResponse(char ch) {
        // Check if the character is a valid response ('Y', 'y', 'N', 'n')
        return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
    }

    bool yes() {
        char ch = 0; // Initialize character to store user input
        do {
            cin >> ch; // Read a character from the user
            flushkeys(); // Clear the input buffer
        } while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
        // Repeat until a valid response is received
        return ch == 'y' || ch == 'Y'; // Return true if the response is affirmative
    }

    void readCstr(char cstr[], int len) {
        char buf[1024] = {}; // Buffer to store the input string
        int i;
        cin.getline(buf, 1024); // Read a line of text
        for (i = 0; i < len && buf[i]; i++) {
            cstr[i] = buf[i]; // Copy characters to cstr array
        }
        cstr[i] = 0; // Null-terminate the string
    }

    int readInt(int min, int max) {
        int value = 0; // Variable to store the integer value
        bool done = false;
        while (!done) {
            cin >> value; // Read an integer value
            if (!cin) {
                cin.clear(); // Clear error state of cin
                cout << "Bad integer, try again: ";
            }
            else {
                if (value >= min && value <= max) {
                    done = true; // Value is within range, exit the loop
                }
                else {
                    cout << "Value out of range (" << min << "<=value<=" << max << "): ";
                }
            }
            flushkeys(); // Clear the input buffer
        }
        return value; // Return the validated integer
    }

} // End of namespace sdds
