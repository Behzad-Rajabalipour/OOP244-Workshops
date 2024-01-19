#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Publication.h"
#include <cstring>
#include "iomanip"

using namespace std;

namespace sdds {
	// Default constructor
	Publication::Publication() {
		setDefault();
	}

	// Destructor
	Publication::~Publication() {
		delete[] m_title;
	}

	// Copy constructor
	Publication::Publication(const Publication& ob1) {
		*this = ob1;
	}

	// Copy assignment operator
	Publication& Publication::operator=(const Publication& ob1) {
		// Copying values from ob1 to the current object
		set(ob1.m_membership);
		setRef(ob1.m_libRef);
		strcpy(m_shelfId, ob1.m_shelfId);
		m_date = ob1.m_date;

		// Deleting existing title if any
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}

		// Copying title from ob1 to the current object
		if (ob1.m_title != nullptr) {
			m_title = new char[strlen(ob1.m_title) + 1];
			strcpy(m_title, ob1.m_title);
		}
		else {
			m_title = nullptr;
		}

		return *this;
	}

	// Set default values for a Publication object
	void Publication::setDefault() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}

	// Set member ID for a Publication object
	void Publication::set(int member_id) {
		m_membership = member_id;
	}

	// Set library reference for a Publication object
	void Publication::setRef(int value) {
		m_libRef = value;
	}

	// Reset the checkout date for a Publication object
	void Publication::resetDate() {
		m_date = Date();
	}

	// Get the type of the publication (P for Publication)
	char Publication::type() const {
		return 'P';
	}

	// Check if a Publication is on loan
	bool Publication::onLoan() const {
		return (m_membership != 0);
	}

	// Get the checkout date for a Publication
	Date Publication::checkoutDate() const {
		return m_date;
	}

	// Check if the IO is from console or file
	bool Publication::conIO(ios& io) const {
		return &io == &cin || &io == &cout;
	}

	// Compare a Publication's title with a given title
	bool Publication::operator==(const char* title) const {
		return strstr(m_title, title) != nullptr;
	}

	// Conversion operator to check if a Publication is valid
	Publication::operator bool() const {
		return (m_title != nullptr && m_shelfId[0] != '\0');
	}

	// Conversion operator to get the title of a Publication
	Publication::operator const char* () const {
		return m_title;
	}

	// Get the library reference for a Publication
	int Publication::getRef() const {
		return m_libRef;
	}

	// Write the Publication information to an output stream
	ostream& Publication::write(ostream& os) const {
		if (conIO(os)) {
			// Output for console
			os << "| " << m_shelfId << " | "
				<< setw(30) << left << setfill('.')
				<< m_title << " | ";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << " | " << m_date << " |";
		}
		else {
			// Output for file
			os << type();
			os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
			(m_membership != 0) ? os << m_membership : os << "N/A";
			os << "\t" << m_date;
		}

		return os;
	}

	// Read the Publication information from an input stream
	istream& Publication::read(istream& istr) {
		char t_title[SDDS_TITLE_WIDTH + 1] = {};
		char t_shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int t_libRef = -1, t_membership = 0;
		Date t_Date;

		// Resetting existing title
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
		setDefault();

		// Reading input based on the source (console or file)
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1);

			if (strlen(t_shelfId) != SDDS_SHELF_ID_LEN)
				istr.setstate(ios::failbit);

			cout << "Title: ";
			istr.getline(t_title, SDDS_TITLE_WIDTH + 1);
			if (strlen(t_title) > SDDS_TITLE_WIDTH)
				istr.setstate(ios::failbit);

			cout << "Date: ";
			istr >> t_Date;
		}
		else {
			// Reading from file
			istr >> t_libRef;
			istr.ignore();
			istr.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(t_title, SDDS_TITLE_WIDTH + 1, '\t');
			istr >> t_membership;
			istr.ignore();
			istr >> t_Date;
		}

		// Checking if the date is valid
		if (!t_Date)
			istr.setstate(ios::failbit);

		// Assigning values if input is valid
		if (istr) {
			m_title = new char[strlen(t_title) + 1];
			strcpy(m_title, t_title);
			strcpy(m_shelfId, t_shelfId);
			m_membership = t_membership;
			m_date = t_Date;
			m_libRef = t_libRef;
		}

		return istr;
	}
}
