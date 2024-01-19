#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <iostream>
#include <cstring> // Include C string library for standard string functions
#include <string>
#include "cstring.h" // Include custom cstring header file

namespace sdds { // Start of sdds namespace

    // Function to copy a C-style string
    void strCpy(char* des, const char* src) {
        strcpy(des, src); // Uses standard strcpy to copy src to des
    }

    // Function to copy a C-style string up to a specified length
    void strnCpy(char* des, const char* src, int len) {
        strncpy(des, src, len); // Uses standard strncpy to copy src to des up to len characters
    }

    // Function to compare two C-style strings
    int strCmp(const char* s1, const char* s2) {
        return strcmp(s1, s2); // Uses standard strcmp to compare s1 and s2
    }

    // Function to compare two C-style strings up to a specified length
    int strnCmp(const char* s1, const char* s2, int len) {
        return strncmp(s1, s2, len); // Uses standard strncmp to compare s1 and s2 up to len characters
    }

    // Function to get the length of a C-style string
    int strLen(const char* s) {
        return strlen(s); // Uses standard strlen to get the length of s
    }

    // Function to find a substring within a C-style string
    const char* strStr(const char* str1, const char* str2) {
        return strstr(str1, str2); // Uses standard strstr to find str2 within str1
    }

    // Function to concatenate two C-style strings
    void strCat(char* des, const char* src) {
        strcat(des, src); // Uses standard strcat to append src to the end of des
    }

} // End of sdds namespace
