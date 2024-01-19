#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include "Utils.h"
#include "string.h"
#include "iomanip"

using namespace std;

namespace sdds {
    // MenuItem class
    MenuItem::MenuItem() {
        // Constructor: Initializes an empty MenuItem
        setEmpty();
    }

    MenuItem::MenuItem(const char* content) {
        // Constructor: Initializes MenuItem with the given content
        if (isValid(content)) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
        else {
            // If content is invalid, set MenuItem to empty
            setEmpty();
        }
    }

    void MenuItem::setEmpty() {
        // Helper function: Sets MenuItem to an empty state
        m_content = nullptr;
    }

    bool MenuItem::isValid(const char* content) const {
        // Helper function: Checks if content is valid (not null and not an empty string)
        return (content && content[0] != '\0');
    }

    bool MenuItem::isValid() const {
        // Checks if MenuItem has valid content
        return (m_content && m_content[0] != '\0');
    }

    MenuItem::~MenuItem() {
        // Destructor: Deallocates memory for MenuItem content
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        // Conversion to bool: Checks if MenuItem has valid content
        return (m_content && m_content[0] != '\0');
    }

    MenuItem::operator char* () const {
        // Conversion to char*: Returns the content of MenuItem
        return m_content;
    }

    ostream& MenuItem::display(ostream& ostr) const {
        // Display function: Outputs MenuItem content to the ostream if it has valid content
        if (*this) ostr << m_content;
        return ostr;
    }

    //-------------------------------------------------------------------------
    // Menu class
    Menu::Menu() {
        // Constructor: Initializes an empty Menu
        setEmpty();
    }

    Menu::Menu(const char* title) : menuItem_title(title) {
        // Constructor: Initializes Menu with a title and sets it to empty
        setEmpty();
    }

    Menu::~Menu() {
        // Destructor: Deallocates memory for MenuItems
        for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
            delete menuItems[i];
        }
    }

    void Menu::setEmpty() {
        // Helper function: Sets Menu to an empty state
        for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
            menuItems[i] = nullptr;
        }
        *menuItems = nullptr;
        Counter = 0;
    }

    Menu::operator bool() {
        // Conversion to bool: Checks if the Menu has any items
        return Counter > 0;
    }

    Menu::operator int() {
        // Conversion to int: Returns the number of items in the Menu
        return Counter;
    }

    Menu::operator unsigned int() {
        // Conversion to unsigned int: Returns the number of items in the Menu
        return Counter;
    }

    int Menu::operator~() {
        // Conversion to int: Calls the run() function
        return run();
    }

    ostream& Menu::displayMenuTitle(ostream& ostr) const {
        // Display function: Outputs the title of the Menu to the ostream
        return menuItem_title.display(ostr);
    }

    ostream& Menu::displayMenu(ostream& ostr) const {
        // Display function: Outputs the entire Menu to the ostream
        if (menuItem_title) {
            menuItem_title.display() << endl;
        }

        for (unsigned i = 0; i < Counter; i++) {
            ostr.width(2);
            ostr.setf(ios::right);
            ostr.fill(' ');
            ostr << i + 1 << "- ";
            ostr.unsetf(ios::right);
            menuItems[i]->display(ostr) << endl;
        }
        ostr << " 0- Exit" << "\n" << "> ";

        return ostr;
    }

    int Menu::run() {
        // Run function: Displays the Menu and gets user input
        displayMenu();
        int number = getInteger(0, Counter);
        return (number == 1);
    }

    char* Menu::operator[](unsigned int index) const {
        // Subscript operator: Returns the content of the MenuItem at the specified index
        while (index > Counter)
            index %= Counter;
        return menuItems[index]->m_content;
    }

    Menu& Menu::operator<<(const char* menuitemContent) {
        // Insertion operator: Adds a new MenuItem to the Menu
        if (Counter < MAX_MENU_ITEMS) {
            MenuItem* newMenuItem = new MenuItem(menuitemContent);
            menuItems[Counter] = nullptr;
            menuItems[Counter] = newMenuItem;
            Counter++;
        }
        return *this;
    }

    // Outside of the class
    ostream& operator<<(ostream& ostr, Menu& ob1) {
        // Insertion operator: Outputs the Menu title to the ostream
        return ob1.displayMenuTitle(ostr);
    }

}  // namespace sdds
