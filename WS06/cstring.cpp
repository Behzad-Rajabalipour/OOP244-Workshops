#define _CRT_SECURE_NO_WARNINGS  // Prevents the compiler from suggesting secure versions of standard library functions

#include "cstring.h"  // Include the custom string header file
#include <string.h>   // Include the standard string header file for string manipulation functions

namespace sdds {
    // Function strCpy: Copies the source string to the destination string
    void strCpy(char* des, const char* src) {
        strcpy(des, src);  // Uses the standard library function strcpy to copy src to des
    }

    // Function strLen: Returns the length of the string
    int strLen(const char* s) {
        return strlen(s);  // Uses the standard library function strlen to calculate the length of s
    }

    // Function strCat: Appends the source string to the end of the destination string
    void strCat(char* des, const char* src) {
        strcat(des, src);  // Uses the standard library function strcat to append src to the end of des
    }
}
