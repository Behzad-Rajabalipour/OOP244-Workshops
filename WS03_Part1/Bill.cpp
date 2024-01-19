#include <iostream>
#include "cstring.h" // Custom string handling functions
#include "Bill.h" // Bill class definition
#include "iomanip" // Input-output manipulators for formatting

using namespace std;

namespace sdds {
    // Initializes the Bill object with a given title and number of items
    void Bill::init(const char* title, int noOfItem) {
        if (title && noOfItem) {
            m_noOfItems = noOfItem;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36); // Copy the title to m_title with a maximum of 36 characters
            m_items = new Item[m_noOfItems]; // Dynamically allocate an array of Items
            for (int i = 0; i < m_noOfItems; i++)
                m_items[i].setEmpty(); // Initialize each Item in the array
        }
        // else block for invalid parameters can be added here if required
    }

    // Adds an item to the Bill if there is space
    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed); // Set the item details
            m_itemsAdded++;
            return true; // Item added successfully
        }
        return false; // No more space to add the item
    }

    // Sets the Bill to an empty state
    void Bill::setEmpty() {
        strnCpy(m_title, "", 1); // Set title to an empty string
        m_items = nullptr; // Set the items pointer to nullptr
    }

    // Calculates the total tax of all items
    double Bill::totalTax() const {
        double sum = 0.0;
        for (int i = 0; i < m_noOfItems; i++)
            sum += m_items[i].tax(); // Accumulate the tax for each item
        return sum;
    }

    // Calculates the total price of all items (excluding tax)
    double Bill::totalPrice() const {
        double sum = 0.0;
        for (int i = 0; i < m_noOfItems; i++)
            sum += m_items[i].price(); // Accumulate the price for each item
        return sum;
    }

    // Displays the Bill title
    void Bill::Title() const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) // Check if the Bill is valid
            cout << "| " << setw(36) << left << m_title << " |" << endl; // Display title
        else
            cout << "| Invalid Bill                         |" << endl; // Display invalid message

        // Header for items
        cout << "+----------------------+---------+-----+" << endl
            << "| Item Name            | Price   + Tax |" << endl
            << "+----------------------+---------+-----+" << endl;
    }

    // Displays the Bill footer
    void Bill::footer() const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) { // Check if the Bill is valid
            // Display totals
            cout << "|                Total Tax: " << setw(10) << right << totalTax() << " |" << endl
                << "|              Total Price: " << setw(10) << right << totalPrice() << " |" << endl
                << "|          Total After Tax: " << setw(10) << right << totalTax() + totalPrice() << " |" << endl;
        }
        else
            cout << "| Invalid Bill                         |" << endl; // Display invalid message

        cout << "+--------------------------------------+" << endl;
    }

    // Checks if the Bill is valid (all items are valid)
    bool Bill::isValid() const {
        if (m_title[0] != '\0' && m_items != nullptr) {
            for (int i = 0; i < m_noOfItems; i++)
                if (!m_items[i].isValid())
                    return false; // Return false if any item is invalid
            return true; // All items are valid
        }
        return false; // Bill is invalid if title is empty or items pointer is null
    }

    // Displays the Bill
    void Bill::display() const {
        Title(); // Display the title
        for (int i = 0; i < m_noOfItems; i++)
            m_items[i].display(); // Display each item
        footer(); // Display the footer
    }

    // Deallocates dynamic memory allocated for items
    void Bill::deallocate() {
        delete[] m_items; // Delete the array of items
        m_items = nullptr; // Set the items pointer to nullptr
    }

}
