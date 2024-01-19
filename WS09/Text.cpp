#include <fstream>
#include "Text.h"
#include "cstring.h"

using namespace std;

namespace sdds {
    // Get the length of the file
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) { // Continue until the end of the file is reached
            fin.get(); // Read a character
            len += !!fin; // Increase length if a character was read (using double negation)
        }
        return len;
    }

    // Read the content of the file into m_content
    void Text::read() {
        char ch;
        int i = 0;

        ifstream fread(m_filename);

        if (m_content) {
            delete[](m_content);
            m_content = nullptr;
        }

        if (fread.is_open()) {
            m_content = new char[getFileLength() + 1];
            while (fread.get(ch)) {
                m_content[i] = ch; // Copy character by character
                i++;
            }
            m_content[i] = '\0'; // Null-terminate the content
        }
    }

    // Constructor with filename parameter
    Text::Text(const char* filename) {
        if (filename) {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read(); // Read file content
        }
    }

    // Copy constructor
    Text::Text(const Text& ob1) {
        *this = ob1; // Call the copy assignment operator to perform the copy
    }

    // Destructor
    Text::~Text() {
        if (m_filename) {
            delete[](m_filename);
            m_filename = nullptr;
        }

        if (m_content) {
            delete[](m_content);
            m_content = nullptr;
        }
    }

    // Copy assignment operator
    Text& Text::operator=(const Text& ob1) {
        if (this != &ob1) { // Check for self-assignment
            if (m_filename) {
                delete[] m_filename;
                m_filename = nullptr;
            }
            if (ob1.m_filename) {
                m_filename = new char[strLen(ob1.m_filename) + 1];
                strCpy(m_filename, ob1.m_filename);
                read(); // Read file content
            }
        }
        return *this;
    }

    // Write the content to an ostream
    void Text::write(ostream& os) const {
        if (m_content) os << m_content; // Write content if it exists
    }

    // Overloaded subscript operator for accessing characters in the content
    const char& Text::operator[](int index) const {
        if (index >= 0 && index < getFileLength())
            return m_content[index]; // Return the character at the specified index
        else
            return m_content[getFileLength()]; // Return null character if index is out of bounds
    }

    // Overloaded insertion operator to write Text object to ostream
    ostream& operator<<(ostream& ostr, const Text& ob1) {
        ob1.write(ostr); // Call the write function to output the content
        return ostr;
    }
}
