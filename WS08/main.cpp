/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include "Shape.h"
#include "Rectangle.h"
#include "Line.h"
using namespace sdds;
using namespace std;

int main() {
    cout << "Nothing should be printed between these two lines" << endl;
    cout << "------------------------------------" << endl;

    Line BadOne; // Create a Line object with default values
    Rectangle BadRectangle("Bad one", 1, 1); // Create a Rectangle object with specified values

    cout << "------------------------------------" << endl;

    Line* L = new Line("Separator", 50); // Create a Line pointer with a specified label and length
    Rectangle* R = new Rectangle("Container", 30, 5); // Create a Rectangle pointer with specified label, width, and height

    Shape* S[2] = { L, R }; // Create an array of Shape pointers and initialize them with Line and Rectangle pointers

    cout << BadOne << BadRectangle; // Print Line and Rectangle objects
    cout << *L << endl; // Print Line object using the dereferenced pointer
    cout << *R << endl; // Print Rectangle object using the dereferenced pointer

    cout << "Enter the following:\n>Line two,40<ETNER>\n>"; // Prompt user for input
    cin >> *L; // Read Line object from user input

    cout << "The following outputs should be the same" << endl;
    cout << "The correct output:" << endl;
    cout << "Line two\n========================================" << endl;
    cout << "Your output:" << endl;
    cout << *L << endl; // Print Line object

    cout << "Enter the following:\n>A 50 by 4 frame to be printed on screen,50,4<ETNER>\n>"; // Prompt user for input
    cin >> *R; // Read Rectangle object from user input

    cout << "The following outputs should be the same" << endl;
    cout << "The correct output:" << endl;
    cout << "+------------------------------------------------+\n"
        "| A 50 by 4 frame to be printed on screen        |\n"
        "|                                                |\n"
        "+------------------------------------------------+" << endl;
    cout << "Your output:" << endl;
    cout << *R << endl; // Print Rectangle object

    cout << "printing Line and Rectangle using Shape pointers: " << endl;
    cout << *S[0] << endl << *S[1] << endl; // Print Line and Rectangle objects using Shape pointers (virtual function)

    delete S[0]; // Delete Line object
    delete S[1]; // Delete Rectangle object

    cout << "Reading the data from a file" << endl;
    ifstream file("ws8data.csv"); // Open a file for reading

    Shape* sptr; // Declare a pointer to Shape (base class)
    char type;

    while (file) {
        sptr = nullptr;
        type = 'x';
        file.get(type); // Read the type (L or R) from the file
        file.ignore();  // Ignore the newline character

        if (type == 'L') {
            sptr = new Line; // Dynamically create a Line object
        }
        else if (type == 'R') {
            sptr = new Rectangle; // Dynamically create a Rectangle object
        }

        if (sptr) {
            file >> *sptr; // Read data for the specific shape (Line or Rectangle)
            cout << *sptr << endl; // Print the shape
            delete sptr; // Delete the dynamically created shape object
        }
    }

    return 0;
}
