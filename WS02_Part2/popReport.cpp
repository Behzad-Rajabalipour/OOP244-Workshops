#include "Population.h" // Include the Population structure and related functions

using namespace sdds; // Use the sdds namespace

int main() {
    // Load population data from the specified file
    if (load("PCpopulations.csv")) { // If the load function returns true (data successfully loaded)
        display(); // Display the population data
    }
    deallocateMemory(); // Deallocate any dynamically allocated memory
    return 0; // Return 0 to indicate successful program termination
}
