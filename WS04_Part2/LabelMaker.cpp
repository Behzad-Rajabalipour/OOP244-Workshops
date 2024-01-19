#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <iostream>
#include "LabelMaker.h" // Include the LabelMaker class definition
#include "iomanip" // Include IO manipulators for formatting output
#include "cstring.h" // Include custom string handling functions

using namespace std;

namespace sdds {
    // Constructor for the LabelMaker class
    LabelMaker::LabelMaker(int noOFLabels) {
        this->noOFLabels = noOFLabels; // Set the number of labels
        labelsArray = new char*[noOFLabels]; // Dynamically allocate an array of pointers to char arrays (strings)
        for (int i = 0; i < noOFLabels; i++) {
            labelsArray[i] = new char[71]; // Dynamically allocate memory for each string, with a maximum length of 70 characters plus a null terminator
        }
    }

    // Method to read labels from the user
    void LabelMaker::readLabels() {
        cout << "Enter " << noOFLabels << " labels:" << endl;
        for (int i = 0; i < noOFLabels; i++) {
            cout << "Enter label number " << i + 1 << endl << "> ";
            cin.getline(labelsArray[i], 71); // Read each label from the user input, up to 70 characters
        }
    }

    // Method to print all labels in a formatted way
    void LabelMaker::printLabels() {
        int lenTemp; // Variable to hold the length of the label
        for (int i = 0; i < noOFLabels; i++) {
            lenTemp = strLen(labelsArray[i]); // Get the length of the label
            // Print the label with a border
            cout << '+' << setw(lenTemp + 3) << setfill('-') << '+' << endl
                 << "| " << setw(lenTemp + 2) << setfill(' ') << " |" << endl
                 << "| " << setw(lenTemp) << labelsArray[i] << " |" << endl
                 << "| " << setw(lenTemp + 2) << setfill(' ') << " |" << endl
                 << '+' << setw(lenTemp + 3) << setfill('-') << '+' << endl;
        }
    }

    // Destructor for the LabelMaker class
    LabelMaker::~LabelMaker() {
        for (int i = 0; i < noOFLabels; i++) {
            delete[] labelsArray[i]; // Deallocate each string in the array
        }
        delete[] labelsArray; // Deallocate the array of pointers
    }
}
