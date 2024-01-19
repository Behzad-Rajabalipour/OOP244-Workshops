#ifndef SDDS_CSTRING_H_ // Include guard to prevent multiple inclusions of this header
#define SDDS_CSTRING_H_

namespace sdds {
    // The sdds namespace contains custom string manipulation functions.

    // Compares two C-style strings (const char*).
    // Returns true if they are the same, false otherwise.
    bool strCmp(const char*, const char*);

    // Calculates the length of a C-style string (const char*).
    // Returns the number of characters in the string, not including the null terminator.
    int strLen(const char* const);

    // Copies the content of one C-style string (const char*) to another (char*).
    // The destination string will contain the same content as the source string after the operation.
    void strCpy(char*, const char*);
}

#endif // !SDDS_CSTRING_H_
