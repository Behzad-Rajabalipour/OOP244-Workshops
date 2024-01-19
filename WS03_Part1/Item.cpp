#include <iostream>
#include "cstring.h" // Custom string handling functions
#include "Item.h" // Item structure definition
#include "iomanip" // Input-output manipulators

using namespace std;

namespace sdds {
    // Function to set the name of an item
    void Item::setName(const char* name) {
        strnCpy(m_itemName, name, 20); // Copy the name to m_itemName with a maximum of 20 characters
    }

    // Function to set the item to an empty state
    void Item::setEmpty() {
        m_price = 0.0; // Set the price to 0.0
        strnCpy(m_itemName, "", 1); // Set the item name to an empty string
    }

    // Function to set the details of an item
    void Item::set(const char* name, double price, bool taxed) {
        if (price > 0 && name) { // Check if the price is positive and name is not null
            setName(name); // Set the name of the item
            m_price = price; // Set the price of the item
            m_taxed = taxed; // Set the tax status of the item
        }
    }

    // Function to check if the item is valid (price is not zero)
    bool Item::isValid() const {
        return m_price != 0.0; // Return true if the price is not zero
    }

    // Function to calculate the tax for the item
    double Item::tax() const {
        if (isValid()) // Check if the item is valid
            return (double)(m_taxed ? m_price * 0.13 : 0.0); // Calculate tax if the item is taxed
        return 0.0; // Return 0.0 if the item is not valid
    }

    // Function to get the price of the item
    double Item::price() const {
        return m_price; // Return the price of the item
    }

    // Function to display the item details
    void Item::display() const {
        if (isValid()) // Check if the item is valid
            // Display the item details in a formatted way
            cout << "| " << setw(20) << left << setfill('.') << m_itemName
            << " | " << setw(7) << right << fixed << setprecision(2) << setfill(' ') << m_price
            << " | " << (m_taxed ? "Yes" : "No ") << " |" << endl;
        else
            // Display a placeholder if the item is not valid
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
    }

}
