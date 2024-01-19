#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Book.h"
#include <cstring>
#include "iomanip"

using namespace std;

namespace sdds {
	Book::Book() {
    setBookEmpty();
}

Book::Book(const Book& ob1) : Publication(ob1) {
    // Copy constructor for Book class, initializing base class (Publication) with ob1
    // Ensures proper copying of base class attributes and derived class-specific attributes

    // Clean up existing authorName
    if (authorName) {
        delete[] authorName;
        authorName = nullptr;
    }

    // Allocate memory for authorName and copy content from ob1
    authorName = new char[strlen(ob1.authorName) + 1];
    strcpy(authorName, ob1.authorName);
}

Book& Book::operator=(const Book& book) {
    // Assignment operator for Book class, assigning base class (Publication) attributes from book

    // Call base class's assignment operator
    Publication::operator=(book);

    // Clean up existing authorName
    if (authorName) {
        delete[] authorName;
        authorName = nullptr;
    }

    // Allocate memory for authorName and copy content from book
    if (book.authorName) {
        authorName = new char[strlen(book.authorName) + 1];
        strcpy(authorName, book.authorName);
    }

    return *this;
}

Book::~Book() {
    // Destructor for Book class, cleaning up dynamically allocated memory
    delete[] authorName;
}

ostream& Book::write(ostream& os) const {
    // Write function to display Book information

    // Call write function of the base class (Publication)
    Publication::write(os);

    if (Publication::conIO(os)) {
        // If writing to console, format and display authorName
        char author[SDDS_AUTHOR_WIDTH + 1]{ 0 };
        strncpy(author, authorName, SDDS_AUTHOR_WIDTH);
        os << " ";
        os << setw(SDDS_AUTHOR_WIDTH) << left << setfill(' ') << author << " |";
    }
    else {
        // If writing to file, display authorName with appropriate formatting
        os << "\t" << authorName;
    }

    return os;
}

istream& Book::read(istream& is) {
    // Read function to input Book information

    // Call read function of the base class (Publication)
    Publication::read(is);

    char author[256] = { 0 };

    // Clean up existing authorName
    if (authorName) {
        delete[] authorName;
        authorName = nullptr;
    }

    if (Publication::conIO(is)) {
        // If reading from console, ignore newline and prompt for author input
        is.ignore();
        cout << "Author: ";
    }
    else {
        // If reading from file, ignore up to the next tab character
        is.ignore(1000, '\t');
    }

    // Read author input
    is.get(author, 256);

    if (is) {
        // If input is successful, allocate memory for authorName and copy content
        authorName = new char[strlen(author) + 1];
        strcpy(authorName, author);
    }

    return is;
}

char Book::type() const {
    // Function to return the type identifier for Book class
    return 'B';
}

void Book::setBookEmpty() {
    // Function to set Book object to an empty state
    authorName = nullptr;
}

void Book::set(int member_id) {
    // Function to set Book object with member_id and reset date
    Publication::set(member_id);
    Publication::resetDate();
}

Book::operator bool() const {
    // Bool conversion operator for Book class
    // Returns true if authorName is not nullptr and base class is valid (operator bool)
    return authorName && Publication::operator bool();
}

}