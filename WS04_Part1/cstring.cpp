#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include "cstring.h" // Custom string handling functions
#include <cstring> // Include standard C string library for string manipulation functions

namespace sdds {
    // Compares two C-style strings and returns the result
    bool strCmp(const char* name1, const char* name2) {
        if (name1 && name2) // Check if both strings are not null
            return strcmp(name1, name2) == 0; // Use strcmp and return true if strings are equal
        return true; // If one or both strings are null, return true (considered equal)
    }

    // Returns the length of a C-style string
    int strLen(const char* const name1) { // Both pointer and data are not modifiable
        return strlen(name1); // Use strlen to get the length of the string
    }

    // Copies a source C-style string to a destination
    void strCpy(char* name1, const char* name2) {
        if (name1 && name2) // Check if both strings are not null
            strcpy(name1, name2); // Use strcpy to copy name2 to name1
    }
}
