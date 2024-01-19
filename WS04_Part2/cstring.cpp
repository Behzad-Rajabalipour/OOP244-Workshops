#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include "cstring.h" // Include the custom cstring header
#include <cstring> // Include the standard C string library

namespace sdds {
    // Compares two C-style strings
    // Returns true if they are the same, false otherwise
    bool strCmp(const char* name1, const char* name2) {
        if (name1 && name2) {
            return strcmp(name1, name2) == 0; // Uses standard strcmp function for comparison
        }
        return true; // If either string is null, treat them as equal
    }

    // Returns the length of a C-style string
    // The 'const' qualifier indicates that the function does not modify the string
    int strLen(const char* const name1) {
        return strlen(name1); // Uses the standard strlen function to calculate length
    }

    // Copies one C-style string to another
    // Ensures both source and destination pointers are not null before copying
    void strCpy(char* name1, const char* name2) {
        if (name1 && name2) {
            strcpy(name1, name2); // Uses the standard strcpy function to copy the string
        }
    }
}
