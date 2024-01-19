#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <iostream>
#include <cstring> // Include C string library for string manipulation functions
#include <string>
#include "cstring.h" // Include custom cstring header file

namespace sdds {
    // Function to copy a source C-style string to a destination
    void strCpy(char* des, const char* src) {
        strcpy(des, src); // Copies src string to des using the standard strcpy function
    }

    // Function to copy a specified length of a source C-style string to a destination
    void strnCpy(char* des, const char* src, int len) {
        strncpy(des, src, len); // Copies up to len characters from src to des using strncpy
    }

    // Function to compare two C-style strings
    int strCmp(const char* s1, const char* s2) {
        return strcmp(s1, s2); // Compares two strings s1 and s2 using strcmp and returns the result
    }

    // Function to compare a specified length of two C-style strings
    int strnCmp(const char* s1, const char* s2, int len) {
        return strncmp(s1, s2, len); // Compares up to len characters of s1 and s2 using strncmp
    }

    // Function to get the length of a C-style string
    int strLen(const char* s) {
        return strlen(s); // Returns the length of the string s using strlen
    }

    // Function to find a substring within another string
    const char* strStr(const char* str1, const char* str2) {
        return strstr(str1, str2); // Returns a pointer to the first occurrence of str2 in str1 using strstr
    }

    // Function to concatenate a source C-style string to the end of a destination string
    void strCat(char* des, const char* src) {
        strcat(des, src); // Appends the string src to the end of des using strcat
    }
}
