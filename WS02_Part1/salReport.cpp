#include "Employee.h" // Include the Employee structure and related functions

using namespace sdds; // Use the sdds namespace

int main() {
    // Load employee data from a file
    if (load()) { // If the load function returns true (i.e., data is successfully loaded)
        display(); // Display the employee data
    }
    deallocateMemory(); // Deallocate any dynamically allocated memory
    return 0; // Return 0 to indicate successful program termination
}
