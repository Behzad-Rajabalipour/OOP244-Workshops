#include <iostream>
#include "CalorieList.h" // Include the CalorieList class definition

using namespace std;

namespace sdds {
    // Initializes the CalorieList with a given size
    void CalorieList::init(int size_) {
        size = size_;
        m_foodItems = new Food[size]; // Dynamically allocate an array of Food objects
        for (int i = 0; i < size; i++) {
            m_foodItems[i].setEmpty(); // Initialize each Food object to an empty state
        }
    }

    // Adds a food item to the CalorieList
    bool CalorieList::add(const char* item_name, int calorie, int when) {
        if (m_addedItems < size) {
            m_foodItems[m_addedItems].set(item_name, calorie, when); // Set the food item details
            m_addedItems++; // Increment the count of added items
            return true; // Return true to indicate successful addition
        }
        return false; // Return false if the list is full
    }

    // Checks if all food items in the list are valid
    bool CalorieList::isValid() {
        bool flag = true;
        for (int i = 0; i < size; i++) {
            flag = m_foodItems[i].isValid(); // Check if the food item is valid
            if (!flag)
                return false; // Return false if any item is invalid
        }
        return flag; // Return true if all items are valid
    }

    // Displays the CalorieList
    void CalorieList::display() {
        cout << "+----------------------------------------------------+" << endl;

        // Display header based on validity of the list
        if (isValid()) {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }

        // Display column headers
        cout << "+--------------------------------+------+------------+" << endl
            << "| Food name                      | Cals | When       |" << endl
            << "+--------------------------------+------+------------+" << endl;

        int sum_cal = 0; // Variable to store the sum of calories
        for (int i = 0; i < size; i++) {
            m_foodItems[i].display(); // Display each food item
            sum_cal += m_foodItems[i].calories_getter(); // Add the calories of the item to the total
        }

        // Display footer based on validity of the list
        if (isValid()) {
            cout << "+--------------------------------+------+------------+" << endl
                << "|    " << setw(23) << left << "Total Calories for today:   "
                << setw(6) << right << sum_cal << " |            |" << endl;
        }
        else {
            cout << "+--------------------------------+------+------------+" << endl
                << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    // Deallocates dynamic memory allocated for food items
    void CalorieList::deallocate() {
        delete[] m_foodItems; // Delete the array of food items
        m_addedItems = 0; // Reset the count of added items
    }
}
