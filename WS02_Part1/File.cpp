#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <cstdio> // Standard C library for file operations
#include "Employee.h" // Include the Employee struct definition
#include "File.h" // Include file handling functions
#include "string"
#include "cstring.h" // Include custom string handling functions

namespace sdds {

    FILE* fptr; // Global pointer to a file

    // Function to open a file for reading
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r"); // Open the file in read mode
        return fptr != NULL; // Return true if the file is successfully opened
    }

    // Function to count the number of records in the file
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        // Read characters one by one and count the number of newline characters
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr); // Reset the file pointer to the beginning of the file
        return noOfRecs; // Return the count of records
    }

    // Function to close the file
    void closeFile() {
        if (fptr) fclose(fptr); // Close the file if it's open
    }

    // Function to read an integer from the file
    bool read(int& reference) {
        bool success = fscanf(fptr, "%d,", &reference) == 1;
        return success; // Return true if reading is successful
    }

    // Function to read a double from the file
    bool read(double& reference) {
        bool success = fscanf(fptr, "%lf,", &reference) == 1; // %lf is the format specifier for reading a double
        return success; // Return true if reading is successful
    }

    // Function to read a C-style string from the file
    bool read(char* address) {
        bool success = fscanf(fptr, "%[^\n]\n", address) == 1; // Read until a newline is encountered
        return success; // Return true if reading is successful
    }

} // End of namespace sdds
