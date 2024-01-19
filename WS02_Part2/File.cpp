#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <cstdio> // Include standard C library for file operations
#include "File.h" // Include the File.h header file

namespace sdds {
    FILE* fptr; // Global file pointer

    // Function to open a file for reading
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r"); // Open the file in read mode
        return fptr != NULL; // Return true if the file is successfully opened
    }

    // Function to count the number of records in the file
    int noOfRecords() {
        int noOfRecs = 0; // Variable to store the number of records
        char ch; // Variable to read each character from the file
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

    // Function to read a postal code from the file
    bool read(char* postalCode) {
        bool success = fscanf(fptr, "%3s,", postalCode) == 1; // Read 3 characters as string, expect comma delimiter
        return success; // Return true if reading is successful
    }

    // Function to read a population integer from the file
    bool read(int& population) {
        bool success = fscanf(fptr, "%d", &population) == 1; // Read an integer (population)
        return success; // Return true if reading is successful
    }
}
