/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <iostream>
#include <cstdio> // Include standard C library for file operations
#include "CalorieList.h" // Include the CalorieList class definition
using namespace sdds; // Use the sdds namespace
using namespace std;

// Constants for meal times
const int c_breakfast = 1;
const int c_lunch = 2;
const int c_dinner = 3;
const int c_snack = 4;

// Function prototype for testDMA
void testDMA(CalorieList& CL);

int main() {
    CalorieList CL; // Create an instance of CalorieList

    // Initialize and add items to the CalorieList
    CL.init(5);
    CL.add("Cheerios Cereal with 2% milk", 170, c_breakfast);
    CL.display();
    CL.add(nullptr, 100, c_breakfast); // Add invalid item
    CL.add("Cheeseburger", 303, c_lunch);
    CL.add("Pepsi", 150, 0); // Add with invalid meal time
    CL.add("Apple", 52, c_snack);
    CL.display(); // Display the list
    CL.deallocate(); // Deallocate memory

    // Reinitialize and add more items
    CL.init(9);
    CL.add("Cheerios Cereal with 2% milk", 170, c_breakfast);
    CL.add("Tim Hortons Medium coffee double double", 230, c_breakfast);
    CL.add("Cheeseburger", 303, c_lunch);
    CL.add("French Fries", 312, c_lunch);
    CL.add("Pepsi", 150, c_lunch);
    CL.add("Apple", 52, c_snack);
    CL.add("Bread and Cheese", 195, c_dinner);
    CL.add("Garden Salad with Dressing", 220, c_dinner);

    // Attempt to add items beyond the list's capacity
    if (!CL.add("Red Wine", 85, c_dinner)) {
        cout << "This should not be printed!" << endl;
    }
    if (CL.add("This should not be added", 100, c_dinner)) {
        cout << "This should not be printed!" << endl;
    }
    CL.display(); // Display the list
    CL.deallocate(); // Deallocate memory

    //testDMA(CL); // Uncomment to test Dynamic Memory Allocation (DMA)

    return 0;
}

// Function to test dynamic memory allocation (DMA) for the CalorieList
void testDMA(CalorieList& CL) {
    CL.init(1000);
    for (int i = 0; i < 1000; i++) {
        CL.add("Tim Hortons Medium coffee double double", 230, c_breakfast);
    }
    CL.display(); // Display the list
    CL.deallocate(); // Deallocate memory
}
