#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>     // Include the string library for getline
#include <cstring>    // Include the C string functions for strcpy and strlen
#include "LblShape.h"

using namespace std;

namespace sdds {
    // Getter for the label
    const char* LblShape::label() const {
        return m_label;
    }

    // Constructor for LblShape
    LblShape::LblShape(const char* label_) {
        if (label_ && label_[0] != '\0') { // Check if label_ is not null and not an empty string
            m_label = new char[strlen(label_) + 1]; // Allocate memory for m_label
            strcpy(m_label, label_); // Copy label_ to m_label
        }
    }

    // Destructor for LblShape
    LblShape::~LblShape() {
        if (m_label) { // Check if m_label is not null
            delete[] m_label; // Deallocate memory for m_label
            m_label = nullptr; // Set m_label to null
        }
    }

    // Read specifications for LblShape from input stream
    void LblShape::getSpecs(istream& istr) {
        string label_;
        getline(istr, label_, ','); // Read a line until the comma delimiter
        delete[] m_label; // Deallocate previous m_label memory
        m_label = new char[strlen(label_.c_str()) + 1]; // Allocate memory for the new m_label
        strcpy(m_label, label_.c_str()); // Copy the new label to m_label
    }
}
