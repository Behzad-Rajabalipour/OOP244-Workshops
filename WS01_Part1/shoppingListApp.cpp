#define _CRT_SECURE_NO_WARNINGS // Disables warnings related to certain C Standard Library functions
#include <iostream>
#include <cstdlib> // Include standard library for system function
#include "ShoppingList.h" // Include the ShoppingList header file
#include "Utils.h" // Include the Utils header file
#include "File.h" // Include the File header file

using namespace std;
using namespace sdds; // Use the sdds namespace

const bool APP_OS_WINDOWS = false; // Constant to determine the operating system

int listMenu(); // Prototype for the listMenu function

int main() {
    bool done = false; // Flag to control the main loop
    loadList(); // Load the shopping list at the start
    while (!done) {
        system(APP_OS_WINDOWS ? "cls" : "clear"); // Clear the console screen based on OS
        switch (listMenu()) { // Display menu and get user's choice
        case 1:
            toggleBought(); // Toggle the bought status of an item
            break;
        case 2:
            addItemToList(); // Add a new item to the shopping list
            break;
        case 3:
            removeItemfromList(); // Remove an item from the shopping list
            break;
        case 4:
            removeBoughtItems(); // Remove all bought items from the list
            break;
        case 5:
            clearList(); // Clear all items from the shopping list
            break;
        default:
            done = true; // Exit the loop and end the program
        }
    }
    saveList(); // Save the shopping list when exiting
    return 0;
}

int listMenu() {
    cout << "-->>> My Shopping List <<<--" << endl;
    displayList(); // Display the current shopping list
    cout << "----------------------------" << endl
        << "1- Toggle bought Item" << endl
        << "2- Add Shopping Item" << endl
        << "3- Remove Shopping Item" << endl
        << "4- Remove bought Items" << endl
        << "5- Clear List" << endl
        << "0- Exit" << endl << "> ";
    return readInt(0, 5); // Get the user's choice and return it
}
