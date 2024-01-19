#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
	const unsigned MAX_MENU_ITEMS = 20;

	class MenuItem {
		char* m_content;

		// Private member functions
		MenuItem();
		MenuItem(const char*);
		~MenuItem();
		void setEmpty();
		bool isValid(const char*)const;
		bool isValid() const;

		operator bool()const;
		operator char* ()const;
		std::ostream& display(std::ostream & = std::cout)const;

		friend class Menu;
	};

	class Menu {
		MenuItem menuItem_title;
		MenuItem* menuItems[MAX_MENU_ITEMS];

		unsigned Counter;
		void setEmpty();
	public:
		// Constructors and Destructor
		Menu();
		Menu(const char*);
		~Menu();

		// Deleted copy constructor and assignment operator
		Menu(const Menu& M) = delete;
		void operator=(const Menu& M) = delete;

		// Type conversion operators
		operator int();
		operator unsigned int();
		operator bool();
		char* operator [](unsigned int)const;
		int operator~();

		// Display functions
		std::ostream& displayMenuTitle(std::ostream & = std::cout)const;
		std::ostream& displayMenu(std::ostream & = std::cout)const;
		int run();

		// Operator overload for adding menu items
		Menu& operator<<(const char*);
	};

	// Operator overload for displaying menus
	std::ostream& operator<<(std::ostream&, Menu&);
}

#endif
