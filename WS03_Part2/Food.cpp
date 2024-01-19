#include <iostream>
#include "Food.h" // Include the Food class definition

using namespace std;

namespace sdds {
    // Sets the details of a Food item
    void Food::set(const char* item_name, int calories, int when) {
        if (item_name) {
            strNCpy(m_item_name, item_name, 30); // Copy the item name, ensuring it fits within 30 characters
            m_calories = calories; // Set the calorie count
            m_when = when; // Set the time of day (when the food is eaten)
        }
        else {
            setEmpty(); // If item_name is nullptr, set the Food object to an empty state
        }
    }

    // Checks if the Food item is valid
    bool Food::isValid() {
        return 0 < m_calories && m_calories <= 3000 && 1 <= m_when && m_when <= 4; // Validate calories and when
    }

    // Sets the Food object to an empty state
    void Food::setEmpty() {
        strNCpy(m_item_name, "", 29); // Set the item name to an empty string
        m_calories = -1; // Indicate invalid calories
        m_when = -1; // Indicate invalid time of day
    }

    // Returns the calorie count
    int Food::calories_getter() {
        return m_calories; // Return the calorie count
    }

    // Displays the Food item
    void Food::display() {
        if (isValid()) {
            char* temp = new char[21]; // Dynamically allocate memory for temporary string
            // Set the value of temp based on m_when
            switch (m_when) {
            case 1:
                strNCpy(temp, "Breakfast", 20);
                break;
            case 2:
                strNCpy(temp, "Lunch", 20);
                break;
            case 3:
                strNCpy(temp, "Dinner", 20);
                break;
            case 4:
                strNCpy(temp, "Snack", 20);
                break;
            }
            // Display the formatted output
            cout << "| " << setfill('.') << setw(30) << left << m_item_name
                << " | " << setfill(' ') << setw(4) << right << m_calories
                << " | " << setw(10) << left << temp << " |" << endl;
            delete[] temp; // Deallocate the memory allocated to temp
        }
        else {
            // Display placeholder if the Food object is not valid
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }
}
