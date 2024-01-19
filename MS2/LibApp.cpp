#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include "LibApp.h"

using namespace std;

namespace sdds {
	// Constructor for LibApp class
	LibApp::LibApp() : m_mainMenu("Seneca Library Application") {
		// Initialize mainMenu with title and menu items
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		cout << "Loading Data" << endl;
	}

	// Destructor for LibApp class
	LibApp::~LibApp() {

	}

	// Function to confirm user's choice
	bool LibApp::confirm(const char* message) {
		Menu obj(message); // Create a temporary menu object with the given message as the title
		obj << "Yes"; // Add "Yes" as a menu item
		int number = obj.run(); // Display the menu and get the user's choice
		return (number == 1); // Return true if the user selects "Yes," otherwise return false
	}

	// Function to load data
	void LibApp::load() {
		cout << m_mainMenu; // Display the main menu
	}

	// Function to save data
	void LibApp::save() {
		cout << "Changes have been made to the data, what would you like to do?" << endl;
		cout << " 1- Save changes and exit" << endl;
		cout << " 2- Cancel and go back to the main menu" << endl;
		cout << " 0- Exit" << endl;
		cout << "> ";
		int num;
		cin >> num;

		if (num == 1) {
			cout << "Saving Data" << endl;
		}
		else if (num == 0) {
			cout << "This will discard all the changes are you sure?" << endl;
			cout << " 1- Yes" << endl;
			cout << " 0- Exit" << endl;
			cout << "> ";
			cin >> num;
		}
		else if (num == 2) {
			cout << endl;
			run(); // Go back to the main menu
			end = false;
		}
	}

	// Function to search for publications
	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}

	// Function to return a publication
	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl
			<< "Publication returned" << endl << endl;
		m_changed = true; // Mark as changed
	}

	// Function to add a new publication
	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?")) {
			m_changed = true; // Mark as changed
			cout << "Publication added" << endl;
		}
		cout << endl;
	}

	// Function to remove a publication
	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?")) {
			m_changed = true; // Mark as changed
			cout << "Publication removed\n" << endl;
		}
	}

	// Function to check out a publication
	void LibApp::checkOutPub() {
		search();
		if (confirm("Check out publication?")) {
			m_changed = true; // Mark as changed
			cout << "Publication checked out\n" << endl;
		}
	}

	// Function to display the main menu
	void LibApp::display() {
		m_mainMenu.displayMenu();
	}

	// Function to run the library application
	void LibApp::run() {
		display();

		int num;
		bool flag = false;

		cin >> num;
		while (num != 0) {
			if (flag) {
				display();
				cin >> num;
			}
			if (num == 1) {
				newPublication();
				flag = true;
			}
			else if (num == 2) {
				removePublication();
				flag = true;
			}
			else if (num == 3) {
				checkOutPub();
				flag = true;
			}
			else if (num == 4) {
				returnPub();
				flag = true;
			}
		}
		if (m_changed) {
			save();
		}

		if (end == true) {
			cout << endl << "-------------------------------------------" << endl
				<< "Thanks for using Seneca Library Application" << endl;
		}
	}
}
