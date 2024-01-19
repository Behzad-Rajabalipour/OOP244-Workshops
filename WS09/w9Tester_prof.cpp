#include <iostream>
#include <fstream>
#include "HtmlText.h"
#include "Text.h"
using namespace std;
using namespace sdds;

// Function to show the content of a Text object
void show(Text T) {
    cout << "*" << T << "*" << endl; // Display the Text object's content
}

// Function to save HtmlText content to a file
void saveHtml(HtmlText H) {
    ofstream("dcwr.html") << H; // Save the HtmlText object's content to "dcwr.html" file
}

// Function to display the content of a file
void displayFile(const char* filename) {
    cout << "File: " << filename << endl;
    cout << "==================================================" << endl;
    ifstream fin(filename);
    char ch = 0;
    while (fin.get(ch)) {
        cout << ch; // Display the content character by character
    }
    cout << endl << "==================================================" << endl;
}

int main() {
    Text T("test.txt");
    Text Y("dcwr.txt");
    Text Z;
    Y = T; // Copy assignment of Text objects
    Z = Y;
    show(Y); // Show the content of Text object Y

    // Create and manipulate HtmlText objects
    HtmlText H1("dcwr.txt", "Derived Classes and Resources");
    HtmlText H2("dcwr.txt");
    HtmlText H3;
    H2 = H1; // Copy assignment of HtmlText objects
    H3 = H2;
    saveHtml(H3); // Save HtmlText H3 to "dcwr.html"
    displayFile("dcwr.html"); // Display the content of "dcwr.html" file

    return 0;
}
