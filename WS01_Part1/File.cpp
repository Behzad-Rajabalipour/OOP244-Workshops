#define _CRT_SECURE_NO_WARNINGS // Disables warnings related to unsafe functions like fopen, strcpy, etc.
#include <iostream>
#include "File.h" // Include the File header file
using namespace std;

namespace sdds { // Start of namespace sdds

    const char* const SHOPPING_DATA_FILE = "shoppinglist.csv"; // Constant string for the filename
    FILE* sfptr = nullptr; // Pointer to FILE, initialized to nullptr

    bool openFileForRead() {
        sfptr = fopen(SHOPPING_DATA_FILE, "r"); // Open file in read mode
        return sfptr != NULL; // Return true if file opened successfully
    }

    bool openFileForOverwrite() {
        sfptr = fopen(SHOPPING_DATA_FILE, "w"); // Open file in write mode (overwrites existing file)
        return sfptr != NULL; // Return true if file opened successfully
    }

    void closeFile() {
        if (sfptr) fclose(sfptr); // Close file if it is open
    }

    bool freadShoppingRec(ShoppingRec* rec) {
        int flag = 0; // Temporary variable to read the 'bought' status
        bool success = fscanf(sfptr, "%[^,],%d,%d\n",
            rec->m_title, &rec->m_quantity, &flag) == 3; // Read shopping record from file
        rec->m_bought = !!flag; // Convert flag to boolean and store in record
        return success; // Return true if read was successful
    }

    void fwriteShoppintRec(const ShoppingRec* rec) {
        fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought); // Write shopping record to file
    }

} // End of namespace sdds
