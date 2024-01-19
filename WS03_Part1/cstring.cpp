#include "cstring.h" // Include custom string handling functions
#include <cstring> // Include standard C string library
#include <string> // Include C++ string library

namespace sdds {
    // Function to copy a specified length of a source C-style string to a destination
    void strnCpy(char* des, const char* src, int len) {
        strncpy(des, src, len); // Copies up to len characters from src to des using strncpy
        des[len] = '\0'; // Null-terminate the destination string to ensure it's properly closed
    }
}
