#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
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
        set(ob1.m_membership);
        setRef(ob1.m_libRef);
        strcpy(m_shelfId, ob1.m_shelfId);
        m_date = ob1.m_date;

        // Delete the existing title
        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }

        // Copy the title
        if (ob1.m_title != nullptr) {
            m_title = new char[strlen(ob1.m_title) + 1];
            strcpy(m_title, ob1.m_title);
        }
        else {
            m_title = nullptr;
        }

        return *this;
    }

    // Set default values
    void Publication::setDefault() {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    // Set membership ID
    void Publication::set(int member_id) {
        m_membership = member_id;
    }

    // Set reference ID
    void Publication::setRef(int value) {
        m_libRef = value;
    }

    // Reset date to default
    void Publication::resetDate() {
        m_date = Date();
    }

    // Get the type of publication
    char Publication::type() const {
        return 'P';
    }

    // Check if the publication is on loan
    bool Publication::onLoan() const {
        return (m_membership != 0);
    }

    // Get the checkout date
    Date Publication::checkoutDate() const {
        return m_date;
    }

    // Check if the IO stream is console or file
    bool Publication::conIO(ios& io) const {
        return &io == &cin || &io == &cout;
    }

    // Compare the title with a given string
    bool Publication::operator==(const char* title) const {
        return strstr(m_title, title) != nullptr;
    }

    // Conversion operator to bool
    Publication::operator bool() const {
        return (m_title != nullptr && m_shelfId[0] != '\0');
    }

    // Conversion operator to const char*
    Publication::operator const char* () const {
        return m_title;
    }

    // Get the reference ID
    int Publication::getRef() const {
        return m_libRef;
    }

    // Write to the output stream
    ostream& Publication::write(ostream& os) const {
        char t_title[SDDS_TITLE_WIDTH + 1] = { 0 };
        strncpy(t_title, m_title, SDDS_TITLE_WIDTH);

        if (conIO(os)) {
            // Output to console
            os << "| " << m_shelfId << " | "
                << setw(30) << left << setfill('.')
                << t_title << " | ";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << " | " << m_date << " |";
        }
        else {
            // Output to file
            os << type();
            os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
            (m_membership != 0) ? os << m_membership : os << "N/A";
            os << "\t" << m_date;
        }

        return os;
    }

    // Read from the input stream
    istream& Publication::read(istream& is) {
        // Set to Default
        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }

        setDefault();
        m_title = new char[1000];

        if (conIO(is)) {
            // Read from console
            cout << "Shelf No: ";
            is.getline(m_shelfId, SDDS_SHELF_ID_LEN + 1);

            cout << "Title: ";
            is.getline(m_title, 1000, '\n');
            if (strlen(m_title) > SDDS_TITLE_WIDTH) {
                is.clear();
            }

            cout << "Date: ";
            is >> m_date;
        }
        else {
            // Read from file
            is >> m_libRef;
            is.ignore();
            is.getline(m_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            is.getline(m_title, 1000, '\t');
            is >> m_membership;
            is.ignore();
            is >> m_date;
        }

        // Check if the internal Date object has encountered an error during input
        if (!m_date)
            // If an error is detected, set the failbit state for the input stream
            // This will mark the stream as failed and prevent further input until cleared
            is.setstate(ios::failbit);

        return is;
    }

}  // namespace sdds
