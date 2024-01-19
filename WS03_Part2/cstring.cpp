#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <iostream>
#include <cstring> // Include standard C string library for string manipulation functions
#include "cstring.h" // Include custom cstring header file if any

using namespace std;

namespace sdds {
    // Function to copy a specified length of a source C-style string to a destination
    void strNCpy(char* name1, const char* name2, int len) {
        strncpy(name1, name2, len); // Copies up to len characters from name2 to name1 using strncpy
        name1[len] = '\0'; // Null-terminate the destination string to ensure it's properly closed
    }
}
