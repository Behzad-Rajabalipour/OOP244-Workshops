#include "Population.h" // Include the Population structure and related functions

using namespace std;
namespace sdds {
    int noOfRecs; // Global variable to hold the number of records
    Population* populationReport; // Global pointer to array of Population structures

    // Function to sort the population data
    void sort() {
        int i, j;
        Population temp; // Temporary Population structure for swapping
        for (i = noOfRecs - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                // Compare and swap based on population size
                if (populationReport[j].population > populationReport[j + 1].population) {
                    temp = populationReport[j];
                    populationReport[j] = populationReport[j + 1];
                    populationReport[j + 1] = temp;
                }
            }
        }
    }

    // Function to load population data from a file
    bool load(const char filename[]) {
        bool ok = false;
        if (openFile(filename)) { // If file opens successfully
            noOfRecs = noOfRecords(); // Get the number of records
            populationReport = new Population[noOfRecs]; // Allocate dynamic memory for population data
            for (int i = 0; i < noOfRecs; i++) {
                populationReport[i].postal_code = new char[4]; // Allocate memory for postal code
                read(populationReport[i].postal_code); // Read postal code
                read(populationReport[i].population); // Read population
            }

            ok = true; // Set ok to true after successful load
            closeFile(); // Close the file
        }
        else {
            cout << "Could not open data file: FILENAME<ENDL>" << endl;
        }
        return ok; // Return the status of the load operation
    }

    // Function to display the population data
    void display() {
        if (populationReport); // Checks if the populationReport is not null
        int sum = 0; // Variable to store the total population
        sort(); // Sort the population data
        cout << "Postal Code: population\n"
            << "-------------------------\n";
        for (int i = 0; i < noOfRecs; i++) {
            sum += populationReport[i].population; // Add to total population
            cout << i + 1 << "- " << populationReport[i].postal_code << ":" << "  " << populationReport[i].population << endl;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << sum << endl; // Display total population
    }

    // Function to deallocate memory allocated for population data
    void deallocateMemory() {
        for (int i = 0; i < noOfRecs; i++)
            delete[] populationReport[i].postal_code; // Deallocate memory for postal codes
        delete[] populationReport; // Deallocate memory for the populationReport array
    }
}
