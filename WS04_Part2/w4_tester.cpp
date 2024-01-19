/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Version 1.0
// Description
// This is a tester program to demonstrate the functionalities
// of the Label and LabelMaker classes.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Label.h" // Include the Label class definition
#include "LabelMaker.h" // Include the LabelMaker class definition
using namespace sdds;
using namespace std;

int main() {
    int noOfLabels; // Variable to store the number of labels

    // Create a Label for the program title using constructor with frame and content
    Label theProgram("/-\\|/-\\|", "The Label Maker Program"),
        EmptyOne1, // Create an empty label using default constructor
        EmptyOne2("ABCDEFGH"); // Create a label with frame and no content

    // Display the first empty label
    cout << "EmptyOne1" << endl;
    EmptyOne1.printLabel() << endl;

    // Display the second empty label with a frame
    cout << "EmptyOne2" << endl;
    EmptyOne2.printLabel() << endl;

    // Display the program title label
    theProgram.printLabel() << endl << endl;

    // Ask for the number of labels to be created
    cout << "Number of labels to create: ";
    cin >> noOfLabels;
    cin.ignore(10000, '\n'); // Ignore characters in buffer after reading number

    // Create a LabelMaker for the number of labels requested
    LabelMaker lblMkr(noOfLabels);

    // Ask for the label texts
    lblMkr.readLabels();

    // Print the labels
    lblMkr.printLabels();

    return 0;
}
