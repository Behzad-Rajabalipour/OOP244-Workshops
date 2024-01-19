#include <iostream>
#include "ShoppingList.h" // Include the ShoppingList header file

using namespace std;

namespace sdds { // Start of namespace sdds

    // Constants and global variables
    const int MAX_NO_OF_RECS = 15; // Maximum number of shopping records allowed
    ShoppingRec recs[MAX_NO_OF_RECS]; // Array to store shopping records
    int noOfRecs; // Counter for the number of records stored

    // Function to load the shopping list from a file
    bool loadList() {
        ShoppingRec shpr = {}; // Temporary shopping record
        bool ok = false; // Flag to check if file opened successfully
        if (openFileForRead()) { // Open file for reading
            ok = true; // Set flag to true if file opens
            while (noOfRecs < MAX_NO_OF_RECS && freadShoppingRec(&shpr)) {
                recs[noOfRecs++] = shpr; // Read shopping record and store in array
            }
            closeFile(); // Close the file
        }
        return ok; // Return true if loading is successful
    }

    // Function to save the shopping list to a file
    bool saveList() {
        bool ok = false; // Flag to check if file opened successfully
        if (openFileForOverwrite()) { // Open file for writing
            ok = true; // Set flag to true if file opens
            for (int i = 0; i < noOfRecs; i++) {
                fwriteShoppintRec(&recs[i]); // Write each shopping record to file
            }
            closeFile(); // Close the file
        }
        return ok; // Return true if saving is successful
    }

    // Function to remove an item from the shopping list
    void removeItem(int index) {
        if (index >= 0 && index < noOfRecs) { // Check if index is valid
            noOfRecs--; // Decrease record count
            for (int i = index; i < noOfRecs; i++) {
                recs[i] = recs[i + 1]; // Shift records after the removed item
            }
        }
    }

    // Function to clear the entire shopping list
    void clearList() {
        cout << "This will remove all the items from the list;" << endl
            << "Are you sure? (Y)es/(N)o" << endl;
        if (yes()) { // Confirm before clearing
            noOfRecs = 0; // Reset the record count
        }
        else {
            cout << "Cancelled!" << endl; // Cancel operation
        }
    }

    // Function to toggle the bought status of an item in the shopping list
    void toggleBought() {
        cout << "Item number: ";
        toggleBoughtFlag(&recs[readInt(1, noOfRecs) - 1]); // Read item number and toggle its bought status
    }

    // Function to add an item to the shopping list
    void addItemToList() {
        if (noOfRecs < MAX_NO_OF_RECS) { // Check if there is space in the list
            recs[noOfRecs] = getShoppingRec(); // Get a new shopping record
            noOfRecs += !isShoppingRecEmpty(&recs[noOfRecs]); // Increase record count if the record is not empty
        }
        else {
            cout << "Shopping List is full!" << endl; // Inform user if list is full
        }
    }

    // Function to remove an item from the shopping list
    void removeItemfromList() {
        if (!listIsEmpty()) { // Check if the list is not empty
            int value = 0;
            cout << "Item number to delete: ";
            value = readInt(1, noOfRecs); // Get the item number to delete
            cout << "Deleting following item, are you sure?" << endl;
            displayShoppingRec(&recs[value - 1]); // Display item to confirm
            cout << "(Y)es/(N)o: ";
            if (yes()) {
                removeItem(value - 1); // Remove the item if confirmed
            }
            else {
                cout << "Cancelled!" << endl; // Cancel operation
            }
        }
        else {
            cout << "List is empty!" << endl; // Inform user if list is empty
        }
    }

    // Function to display the entire shopping list
    void displayList() {
        for (int i = 0; i < noOfRecs; i++) {
            cout << (i + 1) << "-";
            displayShoppingRec(&recs[i]); // Display each shopping record
        }
    }

    // Function to remove all items marked as bought from the shopping list
    void removeBoughtItems() {
        if (!listIsEmpty()) { // Check if the list is not empty
            cout << "Removing bought items, are you sure?" << endl;
            cout << "(Y)es/(N)o: ";
            if (yes()) { // Confirm before removing
                for (int i = 0; i < noOfRecs; i++) {
                    if (recs[i].m_bought) removeItem(i--); // Remove bought item and adjust index
                }
            }
            else {
                cout << "Cancelled!" << endl; // Cancel operation
            }
        }
        else {
            cout << "List is empty!" << endl; // Inform user if list is empty
        }
    }

    // Function to check if the shopping list is empty
    bool listIsEmpty() {
        return noOfRecs == 0; // Return true if no records are stored
    }

} // End of namespace sdds
