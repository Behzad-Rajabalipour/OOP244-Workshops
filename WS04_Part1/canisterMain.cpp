/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1
// Version 1.0
// Description
// This is a tester program to test the functionalities of the Canister class.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Canister.h" // Include the Canister class definition
using namespace std;
using namespace sdds;

// Function prototype for showing an array of Canisters with a given title
void showCans(const char* title, const Canister* boxArray, int num = 1);

int main() {
    // Create an array of Canister objects using various constructors
    Canister C[] = {
       Canister(), // Default constructor
       Canister(nullptr), // Constructor with nullptr (invalid name)
       Canister("Orange Juice"), // Constructor with content name
       Canister(40, 30), // Constructor with valid dimensions
       Canister(20, 10, "Olive Oil"), // Constructor with valid dimensions and content name
       Canister(9, 20, "Bad ones"), // Constructor with invalid dimensions
       Canister(20, 9), // Constructor with one invalid dimension
       Canister(41, 20, "Bad ones"), // Constructor with one invalid dimension
       Canister(20, 31, "Bad ones") // Constructor with one invalid dimension
    };

    // Display an overview of all canisters
    showCans("Five good ones and 4 bad ones:", C, 9);

    // Clear the contents of some canisters (index 5 to 8)
    for (int i = 5; i < 9; i++) {
        C[i].clear();
    }

    // Display the canisters after clearing some of them
    showCans("All good:", C, 9);

    // Perform operations like setting content and pouring liquid into canisters
    C[5].setContent("Milk").pour(500);
    C[6].setContent("MilK");
    showCans("Milk canisters", &C[5], 2);

    // Pour contents from one canister to another
    C[6].pour(C[5]);
    showCans("Poured one into another", &C[5], 2);
    showCans("Poured 800ccs into the empty canister", &C[5].pour(800), 1);

    // Continue pouring and showing the results
    C[6].pour(C[5]);
    showCans("Filled one with the milk from another", &C[5], 2);
    showCans("Poured 1500ccs of Olive oil into Olive oil canister", &C[4].pour(1500), 1);
    C[5].pour(C[4]);
    showCans("Filled can of milk with olive oil", &C[4], 2);
    showCans("Poured too much into olive oil canister", &C[4].pour(1500), 1);

    // Invalidate some canisters by setting their content to nullptr
    for (int i = 3; i < 9; i++) {
        C[i].setContent(nullptr);
    }

    // Display the state of the canisters after invalidation
    showCans("All bad", &C[3], 6);

    return 0;
}

// Function to display an array of Canisters with a given title
void showCans(const char* title, const Canister* canArray, int num) {
    cout << " " << title << endl;
    cout << " Capacity,  Dimensions            Volume     Content" << endl;
    cout << "------------------------------    ---------  ---------------------------" << endl;
    for (int i = 0; i < num; i++) {
        canArray[i].display() << endl; // Display each Canister in the array
    }
    cout << "------------------------------------------------------------------------" << endl << endl;
}
