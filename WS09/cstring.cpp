#include <iostream>
#include "cstring.h" // Include the custom cstring.h header file

using namespace std;

namespace sdds {
    int strLen(const char* str) {
        int i = 0;
        while (str[i]) { // Loop until the null-terminator character is encountered
            i++;
        }
        return i; // Return the length of the string
    }

    void strCpy(char* str1, const char* str2) {
        int i = 0;
        while (str2[i]) {
            str1[i] = str2[i]; // Copy characters from str2 to str1 one by one
            i++;
        }
        str1[i] = '\0'; // Add a null-terminator to the end of str1 to terminate the string
    }
}
