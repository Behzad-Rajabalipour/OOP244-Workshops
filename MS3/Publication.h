#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_

#include <iostream>
#include <cstring>
#include "Lib.h"
#include "Streamable.h"
#include "Date.h"

namespace sdds {
	class Publication : public Streamable {
		char* m_title;                 // Pointer to char for the title
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];  // Char array for the shelf ID
		int m_membership;              // Membership status
		int m_libRef;                  // Library reference
		Date m_date;                   // Date object for checkout date

	public:
		// Constructors and destructor
		Publication();                  // Default constructor
		Publication(const Publication&); // Copy constructor
		Publication& operator=(const Publication&); // Copy assignment
		~Publication();                 // Destructor

		// Member functions
		virtual void set(int);          // Set member function
		bool conIO(ios&) const;         // Check I/O status
		void setRef(int);               // Set library reference
		void resetDate();               // Reset checkout date
		void setDefault();              // Set default values
		char type() const;              // Get publication type
		bool onLoan() const;            // Check if publication is on loan
		Date checkoutDate() const;      // Get checkout date
		bool operator==(const char*) const;  // Equality comparison with char pointer
		operator bool() const;          // Boolean conversion
		operator const char* () const;  // Char pointer conversion
		int getRef() const;             // Get library reference
		ostream& write(ostream & = cout) const;  // Write publication information
		istream& read(istream & = cin);  // Read publication information
	};
}

#endif // !SDDS_PUBLICATION_H_
