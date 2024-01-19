// Final Project Milestone 3
// Periodical Publication 
// Author    Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "Publication.h"
#include "Utils.h"
#include "Date.h"

using namespace std;
using namespace sdds;

// Function to copy the content of one file to another
void fcopy(const char* dest, const char* source) {
    ifstream fin(source);
    ofstream fout(dest);
    char ch;
    while (fin.get(ch))
        fout << ch;
}

// Function to read a Publication from the input stream
Publication readPublication(istream& istr) {
    Publication P;
    istr >> P;
    return P;
}

// Function to get the next Publication record from the file
Publication getNextRec(ifstream& ifstr) {
    Publication P;
    ifstr >> P;
    ifstr.ignore(1000, '\n');
    return P;
}

int main() {
    sdds::sdds_test = true;  
    Publication pd;
    fcopy("Periodicals.txt", "PeriodicalsOriginal.txt");
    cout << "An Invalid publication printout:" << endl;
    cout << ">" << pd << "<" << endl;
    cout << "Enter the following: " << endl
        << "P1234" << endl
        << "------------------------------" << endl;
    pd = readPublication(cin);
    if (!cin) {  // If cin is in a fail state, clear and ignore the input
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else {
        cout << "This is not supposed to be printed!" << endl;
    }
    cout << "You entered:" << endl;
    cout << ">" << pd << "<" << endl;
    cout << "Enter the following: " << endl
        << "P123" << endl
        << "Seneca Weekly" << endl
        << "2023/13/17" << endl
        << "------------------------------" << endl;
    pd = readPublication(cin);
    if (!cin) {  // If cin is in a fail state, clear and ignore the input
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else {
        cout << "This is not supposed to be printed!" << endl;
    }
    cout << "You entered:" << endl;
    cout << ">" << pd << "<" << endl;
    cout << "Enter the following: " << endl
        << "P123" << endl
        << "Seneca Weekly" << endl
        << "2023/11/17" << endl
        << "------------------------------" << endl;
    pd = readPublication(cin);
    cout << "You entered:" << endl;
    cout << pd << endl;
    cout << "And the title is again: \"" << (const char*)pd << "\"" << endl;  
    pd.set(12345);
    if (pd.onLoan()) {
        cout << "Now this publication is on loan to a member with the id: 12345" << endl;
        pd.resetDate();
        cout << "The checkout date is: " << pd.checkoutDate() << endl;
        pd.setRef(9999);
        cout << "The library unique reference id is: " << pd.getRef() << endl;
        cout << pd << endl;
        cout << "----------------------------------------------------------------" << endl;
    }
    cout << "Adding the periodical publication to the end of the data file:" << endl;
    ofstream fileout("Periodicals.txt", ios::app);  // Append to the file
    if (pd) {
        cout << "appended to the file" << endl;
        fileout << pd << endl;
    }
    fileout.close();
    cout << endl << "Contents of the file:" << endl;
    ifstream filein("Periodicals.txt");  // Read from the file
    char pType{};
    for (int row = 1; filein; row++) {  // Loop until the end of the file
        filein >> pType;  // Get the first character (Record type signature)
        if (pType != 'P') {
            cout << "The Record type signature is supposed to be B, but it is: " << pType << endl;
            filein.setstate(ios::failbit);  // Set failbit to indicate an error
        }
        filein.ignore();
        pd = getNextRec(filein);  // Read the next Publication record
        if (filein) {
            cout << (pd.onLoan() ? "|*" : "| ");  // Print '*' if on loan
            cout.width(4);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << row << (pd.onLoan() ? "*" : " ");  // Print row number with '*' if on loan
            cout.unsetf(ios::right);
            cout << pd << (pd == "Star" ? "<<<" : "") << endl;  // Print additional text for a specific title
        }
    }
    return 0;
}
