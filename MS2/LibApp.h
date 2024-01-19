#ifndef SDDS_LIPAPP_H_
#define SDDS_LIPAPP_H_
#include "Menu.h"

namespace sdds {
	class LibApp {
		bool m_changed = false;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool end = true;

		// Private member function to confirm an action
		bool confirm(const char*);

		// Private member functions for various actions
		void load();
		void save();
		void search();
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();

	public:
		// Constructor
		LibApp();

		// Function to display the library application
		void display();

		// Destructor
		~LibApp();

		// Function to run the library application
		void run();
	};
}

#endif // SDDS_LIPAPP_H_
