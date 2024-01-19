#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <iostream>
#include <cstdio> // Include standard C library for file operations
#include "Bill.h" // Include the Bill class definition
using namespace sdds; // Use the sdds namespace
using namespace std;

void billTester(); // Prototype for the billTester function

int main() {
    FILE* list = fopen("grocery.txt", "r"); // Open the file "grocery.txt" for reading
    int recs = 0; // Variable to store the number of records
    char ch; // Variable to read each character from the file
    Bill B; // Create an instance of the Bill class

    billTester(); // Call the billTester function to run initial tests

    // Process the grocery.txt file if it is successfully opened
    if (list) {
        char name[256]; // Array to store the name of the item
        double price; // Variable to store the price
        int taxed; // Variable to store the taxed status (as an integer)

        // Count the number of records (lines) in the file
        while (fscanf(list, "%c", &ch) == 1) {
            recs += (ch == '\n');
        }
        rewind(list); // Rewind the file pointer to the beginning of the file

        B.init("Grocery Items", recs); // Initialize the Bill object with a title and number of records

        // Read and add each item to the Bill object
        while (fscanf(list, "%[^\t]\t%lf%d\n", name, &price, &taxed) == 3) {
            B.add(name, price, taxed == 1); // Add the item to the bill
        }

        B.display(); // Display the bill
        B.deallocate(); // Deallocate any dynamically allocated memory
        fclose(list); // Close the file
    }
    else {
        cout << "file: grocery.txt not found!" << endl; // File not found error message
    }

    return 0; // Return 0 to indicate successful program termination
}

void billTester() {
    // Test function for the Bill class
    Bill B;
    B.init("Quick Shopping", 5);
    B.add("Milk 2%", 4.99, false);
    B.display();
    B.add(nullptr, 15.50, true);
    B.add("Frying Pan", 24.99, true);
    B.add("Eggs", -2.99, false);
    B.display();
    B.deallocate();
    B.init("Quick Shopping", 5);
    B.add("Milk 2%", 4.99, false);
    B.add("Spatula", 15.50, true);
    B.add("Frying Pan", 24.99, true);
    B.add("Eggs", 5.99, false);
    B.add("Bug Spray", 9.99, true);
    B.display();
    B.deallocate();
}
