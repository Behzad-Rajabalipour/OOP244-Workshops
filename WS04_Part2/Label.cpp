#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <iostream>
#include "Label.h" // Include the Label class definition
#include "cstring.h" // Include custom string handling functions
#include "iomanip" // Include IO manipulators for formatting output

using namespace std;

namespace sdds {
    // Default Constructor
    Label::Label() {
        content[0] = '\0'; // Initialize content as an empty string
        strCpy(frame, "+-+|+-+|"); // Copy default frame pattern to frame
    }

    // Constructor with frame argument
    Label::Label(const char* frameAg) {
        content[0] = '\0'; // Initialize content as an empty string
        strCpy(frame, frameAg); // Copy provided frame pattern into frame
    }

    // Constructor with frame and content arguments
    Label::Label(const char* frameArg, const char* content) {
        strCpy(frame, frameArg); // Copy provided frame pattern into frame
        strCpy(this->content, content); // Copy provided content into content
    }

    // Destructor
    Label::~Label() {
        // The destructor is responsible for deallocating the dynamically allocated memory for frame and content
        delete[] frame;
        delete[] content;
    }

    // Method for reading label content from user input
    void Label::readLabel() {
        cout << "Enter frame: ";
        cin >> frame; // Read frame from user input
        cin.ignore(1000, '\n'); // Clear the input buffer
        cout << "Enter content: ";
        cin >> content; // Read content from user input
    }

    // Method for printing the label with appropriate formatting
    ostream& Label::printLabel() const {
        if (content[0] != '\0') { // Check if content is not empty
            // Print the label using the frame and content with custom formatting
            return (
                cout << frame[0] << setw(strLen(content) + 3) << right << setfill(frame[1]) << frame[2] << endl,
                cout << frame[3] << setw(strLen(content) + 3) << setfill(' ') << frame[3] << endl,
                cout << frame[3] << ' ' << setw(23) << left << content << ' ' << frame[3] << endl,
                cout << frame[3] << setw(strLen(content) + 3) << right << frame[3] << endl,
                cout << frame[6] << setw(strLen(content) + 3) << right << setfill(frame[5]) << frame[4]
                );
        }
        else {
            // If content is empty, return cout without printing any label
            return cout;
        }
    }
}
