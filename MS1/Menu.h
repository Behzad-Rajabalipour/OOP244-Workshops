#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
	const unsigned MAX_MENU_ITEMS = 20;

	class MenuItem {
		char* m_content;
		
		// Default constructor (private)
		MenuItem();

		// Constructor with content
		MenuItem(const char*);

		// Destructor
		~MenuItem();

		// Set the item to empty
		void setEmpty();

		// Check if the content is valid
		bool isValid(const char*)const;

		// Check if the item is valid
		bool isValid() const;

		// Conversion operators
		operator bool()const;
		operator char* ()const;

		// Display the item
		std::ostream& display(std::ostream& = std::cout)const;

		friend class Menu;
	};	

	class Menu {
		MenuItem menuItem_title;
		MenuItem* menuItems[MAX_MENU_ITEMS];
		
		unsigned Counter;

		// Set the menu to empty
		void setEmpty();

	public:
		// Default constructor
		Menu();

		// Constructor with title
		Menu(const char*);

		// Destructor
		~Menu();

		// Copy constructor (deleted)
		Menu(const Menu& M) = delete;

		// Copy assignment (deleted)
		void operator=(const Menu& M) = delete;

		// Conversion operators
		operator int();
		operator unsigned int();
		operator bool();
		char* operator [](unsigned int)const;
		int operator~();

		// Display the menu title
		std::ostream& displayMenuTitle(std::ostream& = std::cout)const;

		// Display the menu
		std::ostream& displayMenu(std::ostream& = std::cout)const;

		// Run the menu
		int run();

		// Add an item to the menu
		Menu& operator<<(const char*);
	};

	// Output operator for menu
	std::ostream& operator<<(std::ostream&, Menu&);
}

#endif
