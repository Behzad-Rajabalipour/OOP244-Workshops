#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <iostream>
#include <iomanip> // Include IO manipulators for formatting output
#include "cstring.h" // Include custom string handling functions
#include "Canister.h" // Include the Canister class definition

using namespace std;

namespace sdds {
    // Default constructor: sets the Canister object to default values
    Canister::Canister() {
        setToDefault(); // Calls the private member function to set default values
    }

    // Constructor with content name: sets the Canister to default and sets content name
    Canister::Canister(const char* contentName) {
        setToDefault(); // Initialize with default values
        setName(contentName); // Set the content name if provided
    }

    // Constructor with dimensions and optional content name
    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault(); // Initialize with default values
        // Check if the dimensions are within specified limits
        if (height >= 10 && height <= 40 && diameter >= 10 && diameter <= 30) {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0.0; // Set the initial volume to 0
            setName(contentName); // Set the content name if provided
        } else {
            m_usable = false; // If dimensions are out of range, set the canister as unusable
        }
    }

    // Private method to set default values for a Canister object
    void Canister::setToDefault() {
        m_contentName = nullptr; // Nullify the pointer to content name
        m_height = 13.0; // Default height
        m_diameter = 10.0; // Default diameter
        m_contentVolume = 0.0; // Default content volume
        m_usable = true; // Set canister as usable by default
    }

    // Destructor: responsible for releasing dynamically allocated memory
    Canister::~Canister() {
        delete[] m_contentName; // Deallocate memory for content name
    }

    // Checks if the canister is empty (minimal content)
    bool Canister::isEmpty() const {
        return m_contentVolume < 0.00001; // A very small volume is considered empty
    }

    // Compares the content of this canister with another canister
    bool Canister::hasSameContent(const Canister& C) const {
        // Compare content names and ensure neither is null
        return strCmp(m_contentName, C.m_contentName) == 0 && m_contentName && C.m_contentName;
    }

    // Sets the content name of the canister
    void Canister::setName(const char* Cstr) {
        delete[] m_contentName; // Deallocate any existing content name
        if (Cstr && m_usable) { // Check if the string is not null and the canister is usable
            // Allocate memory and copy the string
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    // Clears the content of the canister and resets it
    void Canister::clear() {
        delete[] m_contentName; // Deallocate content name memory
        m_contentName = nullptr; // Reset the pointer
        m_contentVolume = 0.0; // Reset the volume
        m_usable = true; // Set canister as usable
    }

    // Calculates the capacity of the canister based on its dimensions
    double Canister::capacity() const {
        double PI = 3.14159265; // Define PI for calculation
        // Calculate capacity based on cylindrical formula
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    // Returns the current volume of content in the canister
    double Canister::volume() const {
        return m_contentVolume; // Return the current volume
    }

    // Sets the content of the canister and returns a reference to it
    Canister& Canister::setContent(const char* contentName) {
        if (contentName && isEmpty()) { // Check if the canister is empty and contentName is not null
            delete[] m_contentName; // Deallocate previous content name
            // Allocate and set new content name
            m_contentName = new char[strLen(contentName) + 1];
            strCpy(m_contentName, contentName);
        } else if (contentName == nullptr) {
            m_usable = false; // If contentName is null, set canister as unusable
        }
        return *this; // Return a reference to this object
    }

    // Pours a specified quantity into the canister and returns a reference to it
    Canister& Canister::pour(double quantity) {
        // Check if pouring the quantity is possible and if the canister is usable
        if (capacity() >= m_contentVolume + quantity && m_usable && quantity > 0) {
            m_contentVolume += quantity; // Add the quantity to the current volume
            return *this; // Return a reference to this object
        }
        m_usable = false; // Set canister as unusable if pouring is not possible
        return *this; // Return a reference to this object
    }

    // Pours content from one canister to another
    Canister& Canister::pour(Canister& ob1) {
        setContent(ob1.m_contentName); // Set the content name from the source canister
        if (m_usable) {
            // Check the capacity and adjust volumes accordingly
            if (capacity() - m_contentVolume < ob1.m_contentVolume) {
                ob1.m_contentVolume -= capacity() - m_contentVolume;
                m_contentVolume = capacity();
            } else {
                pour(ob1.m_contentVolume);
                ob1.m_contentVolume = 0.0;
            }
            // Check if both canisters have the same content
            if (!isEmpty() && strCmp(m_contentName, ob1.m_contentName)) {
                m_usable = false;
            }
        }
        return *this; // Return a reference to this object
    }

    // Display function: prints details of the canister
    ostream& Canister::display() const {
        cout << fixed << setprecision(1) << setw(7) << right << capacity() << "cc ("
             << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable) {
            return cout << " of Unusable content, discard!";
        } else if (m_contentName) {
            return cout << " of " << fixed << setprecision(1)
                        << setw(7) << right << m_contentVolume << "cc   "
                        << m_contentName;
        }
        return cout; // Return the cout stream for chaining
    }
}
