// Header guard to prevent multiple inclusions
#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_

#include <iostream>
#include <cstring>
#include "Lib.h"
#include "Streamable.h"
#include "Date.h"

// Namespace declaration
using namespace std;

namespace sdds {
    // Publication class declaration, derived from Streamable
    class Publication : public Streamable {
        char* m_title;                              // Pointer to hold the title (dynamic memory allocation)
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];      // Array to hold the shelf ID
        int m_membership;                           // Membership information
        int m_libRef;                               // Library reference ID
        Date m_date;                                // Date object for checkout date

    public:
        // Constructors, Destructor, and Copy Assignment
        Publication();                              // Default constructor
        Publication(const Publication&);           // Copy constructor
        Publication& operator=(const Publication&); // Copy assignment
        ~Publication();                             // Destructor

        // Virtual functions from Streamable class
        virtual void set(int);                      // Set the membership information (virtual)
        virtual char type() const;                  // Get the type of the publication (virtual)
        bool conIO(ios&) const;                     // Check if IO is connected to console or file
        void setRef(int);                           // Set the library reference ID
        void resetDate();                           // Reset the checkout date
        void setDefault();                          // Set default values
        bool onLoan() const;                        // Check if the publication is on loan
        Date checkoutDate() const;                  // Get the checkout date
        bool operator==(const char*) const;        // Compare with a C-string title
        operator bool() const;                      // Check if the publication is valid
        operator const char* () const;              // Get the title as a C-string
        int getRef() const;                         // Get the library reference ID

        // Stream operators overloads (declared in Streamable.h => #ref1)
        // ostream& operator<<(ostream&, const Publication&);
        // istream& operator>>(istream&, Publication&);

        // Getter and Setter functions
        ostream& write(ostream & = cout) const;      // Write to the output stream
        istream& read(istream & = cin);              // Read from the input stream
    };

} // namespace sdds

#endif // !SDDS_PUBLICATION_H_
