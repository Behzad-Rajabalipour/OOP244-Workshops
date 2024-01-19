#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include "Publication.h"

namespace sdds {
    // Book class, derived from Publication
    class Book : public Publication {
        char* authorName;  // Pointer to hold the author's name

    public:
        // Default constructor
        Book();

        // Copy constructor
        Book(const Book&);

        // Copy assignment operator
        Book& operator=(const Book&);

        // Destructor
        ~Book();

        // Set the Book object to an empty state
        void setBookEmpty();

        // Return the type of the object ('B' for Book)
        char type() const;

        // Set the Book object based on user input
        void set(int);

        // Conversion operator to bool (check if Book object is not empty)
        operator bool() const;

        // Output the Book object to the ostream
        ostream& write(ostream&) const;

        // Read the Book object from the istream
        istream& read(istream&);
    };
}
#endif // !SDDS_BOOK_H_
