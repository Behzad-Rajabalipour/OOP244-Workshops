#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include "Utils.h"
#include "string.h"
#include "iomanip"

using namespace std;

namespace sdds {
	// Class MenuItem
	MenuItem::MenuItem() {
		setEmpty();
	}

	// Constructor for MenuItem that initializes it with content
	MenuItem::MenuItem(const char* content) {
		if (isValid(content)) {
			m_content = new char[strlen(content) + 1]; // Allocate memory for content
			strcpy(m_content, content); // Copy content into allocated memory
		}
		else {
			setEmpty();
		}
	}

	// Helper function to set MenuItem as empty
	void MenuItem::setEmpty() {
		m_content = nullptr;
	}

	// Check if content is valid (not null or empty)
	bool MenuItem::isValid(const char* content) const {
		return (content && content[0] != '\0');
	}

	// Check if MenuItem is valid
	bool MenuItem::isValid() const {
		return (m_content && m_content[0] != '\0');
	}

	// Destructor for MenuItem
	MenuItem::~MenuItem() {
		delete[] m_content; // Deallocate memory for content
	}

	// Conversion operator to check if MenuItem is valid
	MenuItem::operator bool() const {
		return (m_content && m_content[0] != '\0');
	}

	// Conversion operator to retrieve content as a char pointer
	MenuItem::operator char* () const {
		return m_content;
	}

	// Display the content of MenuItem
	ostream& MenuItem::display(ostream& ostr) const {
		if (*this) ostr << m_content; // If MenuItem is valid, display its content
		return ostr;
	}

	// Class Menu
	Menu::Menu() {
		setEmpty(); // Initialize the Menu as empty
	}

	// Constructor for Menu that sets the title
	Menu::Menu(const char* title) : menuItem_title(title) {
		setEmpty(); // Initialize the Menu as empty
	}

	// Destructor for Menu
	Menu::~Menu() {
		for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
			delete menuItems[i]; // Delete each MenuItem to avoid memory leaks
		}
	}

	// Helper function to set Menu as empty
	void Menu::setEmpty() {
		for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
			menuItems[i] = nullptr; // Initialize all MenuItem pointers to nullptr
		}
		*menuItems = nullptr; // Ensure the first pointer is also nullptr
		Counter = 0; // Initialize the item counter to 0
	}

	// Conversion operator to check if Menu is not empty
	Menu::operator bool() {
		return Counter > 0;
	}

	// Conversion operator to get the number of items in the Menu
	Menu::operator int() {
		return Counter;
	}

	// Conversion operator to get the number of items in the Menu (unsigned)
	Menu::operator unsigned int() {
		return Counter;
	}

	// Inverted conversion operator to run the Menu and return the selected item
	int Menu::operator~() {
		return run();
	}

	// Display the title of the Menu
	ostream& Menu::displayMenuTitle(ostream& ostr) const {
		return menuItem_title.display(ostr);
	}

	// Display the Menu with its items
	ostream& Menu::displayMenu(ostream& ostr) const {
		if (menuItem_title) {
			menuItem_title.display(); // Display the Menu title
			ostr << ":" << endl;
		}

		for (unsigned i = 0; i < Counter; i++) {
			ostr.width(2); // Set output width to 2 characters
			ostr.setf(ios::right); // Align output to the right
			ostr.fill(' '); // Fill with spaces
			ostr << i + 1 << "- "; // Display item number
			ostr.unsetf(ios::right); // Unset right alignment
			menuItems[i]->display(ostr) << endl; // Display MenuItem content
		}
		ostr << " 0- Exit" << "\n" << "> "; // Display exit option
		return ostr;
	}

	// Run the Menu and return the selected item
	int Menu::run() {
		displayMenu(); // Display the Menu
		int number = getInteger(0, Counter); // Get and validate the user's choice
		return number;
	}

	// Access the content of a MenuItem by index
	char* Menu::operator[](unsigned int index) const {
		while (index >= Counter)
			index %= Counter; // Wrap around if the index exceeds the number of items
		return menuItems[index]->m_content; // Get the content of the selected MenuItem
	}

	// Add a new item to the Menu
	Menu& Menu::operator<<(const char* menuitemContent) {
		if (Counter < MAX_MENU_ITEMS) {
			MenuItem* newMenuItem = new MenuItem(menuitemContent); // Create a new MenuItem
			menuItems[Counter] = nullptr;
			menuItems[Counter] = newMenuItem; // Add the new MenuItem to the Menu
			Counter++;
		}
		return *this;
	}

	// Out of the class, display the Menu title
	ostream& operator<<(ostream& ostr, Menu& ob1) {
		return ob1.displayMenuTitle(ostr);
	}
}
