#include <iostream>
#include "ShoppingRec.h" // Include the ShoppingRec header file
using namespace std;

namespace sdds {
    const int MAX_QUANTITY_VALUE = 50; // Maximum quantity value for a shopping record

    // Function to get a shopping record from the user
    ShoppingRec getShoppingRec() {
        ShoppingRec R = {}; // Initialize a new ShoppingRec structure
        cout << "Item name: ";
        readCstr(R.m_title, MAX_TITLE_LENGTH); // Read the item name
        cout << "Quantity: ";
        R.m_quantity = readInt(1, MAX_QUANTITY_VALUE); // Read the item quantity with bounds
        return R; // Return the filled shopping record
    }

    // Function to display a shopping record
    void displayShoppingRec(const ShoppingRec* shp) {
        cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
            " qty:(" << shp->m_quantity << ")" << endl;
        // Display the record with a check mark if it's bought
    }

    // Function to toggle the bought status of a shopping record
    void toggleBoughtFlag(ShoppingRec* rec) {
        rec->m_bought = !rec->m_bought; // Toggle the m_bought flag in the record
    }

    // Function to check if a shopping record is empty
    bool isShoppingRecEmpty(const ShoppingRec* shp) {
        return shp->m_title[0] == 0; // Check if the title is an empty string
    }
}
