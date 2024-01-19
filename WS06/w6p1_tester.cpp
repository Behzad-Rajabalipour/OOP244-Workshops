/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6
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
#include <iostream>                                  // Include the iostream library.
#include <fstream>                                   // Include the fstream library.
#include <string>                                    // Include the string library.
#include "TextFile.h"                                // Include the header file TextFile.h from the sdds namespace.
using namespace sdds;                                // Use the sdds namespace.
using namespace std;                                 // Use the standard namespace.

void FirstTen(TextFile T);                            // Declare a function prototype for FirstTen.
void Copy(const string& dest, const string& source);  // Declare a function prototype for Copy.
void Dump(const string& filename);                    // Declare a function prototype for Dump.

int main() {
    TextFile Empty;                                   // Create an empty TextFile object.
    TextFile BadFilename("badFilename");               // Create a TextFile object with a bad filename.
    Copy("echoes.txt", "echoesOriginal.txt");          // Copy contents from one file to another.
    Copy("seamus.txt", "seamusOriginal.txt");          // Copy contents from one file to another.
    TextFile E;                                       // Create an empty TextFile object.
    TextFile S("seamus.txt");                         // Create a TextFile object with "seamus.txt".
    cout << "Type echoes.txt and hit <ENTER>" << endl;
    cout << "Enter the text file name: ";
    cin >> E;                                         // Input a text file name into E.
    cout << E << endl;                                // Output the contents of E.
    cout << S << endl;                                // Output the contents of S.
    FirstTen(E);                                      // Call the FirstTen function for E.
    FirstTen(S);                                      // Call the FirstTen function for S.
    E = S;                                            // Assign the contents of S to E.
    cout << E << endl;                                // Output the contents of E.
    cout << "============================================================" << endl;
    Dump("echoes.txt");                               // Output the contents of "echoes.txt".
    Dump("seamus.txt");                               // Output the contents of "seamus.txt".
    Dump("C_echoes.txt");                             // Output the contents of "C_echoes.txt".
    Dump("C_seamus.txt");                             // Output the contents of "C_seamus.txt".
    cout << "*" << Empty << BadFilename << "*" << endl; // Output the contents of Empty and BadFilename.
    return 0;
}

void FirstTen(TextFile T) {                           // Define a function that takes a TextFile as input.
    if (T) {                                          // Check if the TextFile is valid (contains data).
        cout << ">>> First ten lines of : " << T.name() << endl;
        for (unsigned i = 0; i < 10; i++) {
            cout << (i + 1) << ": " << T[i] << endl;   // Output the first ten lines of the TextFile.
        }
    }
    else {
        cout << "Nothing to print!" << endl;           // Output a message if the TextFile is empty.
    }
    cout << endl << "-------------------------------------------------------------" << endl;
}

void Dump(const string& filename) {
    cout << "DUMP---------------------------------------------------------" << endl;
    cout << ">>>" << filename << "<<<" << endl;
    ifstream fin(filename.c_str());                    // Open the specified file for reading.
    char ch;
    while (fin.get(ch)) cout << ch;                     // Output the contents of the file character by character.
    cout << endl << "-------------------------------------------------------------" << endl;
}

void Copy(const string& dest, const string& source) {
    ifstream fin(source.c_str());                       // Open the source file for reading.
    ofstream fout(dest.c_str());                        // Open the destination file for writing.
    char ch;
    while (fin.get(ch)) fout << ch;                     // Copy contents from source to destination.
}
