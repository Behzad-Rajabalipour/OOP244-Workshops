#define _CRT_SECURE_NO_WARNINGS // Disables warnings for certain standard C functions
#include <iostream>
#include "cstring.h"  // Include custom string handling functions
#include "Employee.h" // Include the Employee struct definition
#include "File.h"     // Include file handling functions

using namespace std;

namespace sdds {

    int noOfEmployees;      // Global variable to hold the number of employees
    Employee* employees;    // Global pointer to array of Employee structures

    // Function to sort employees by their employee number
    void sort() {
        int i, j;
        Employee temp;       // Temporary Employee structure for swapping
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                // Compare and swap if necessary
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // Function to load one employee record from the file
    bool load(Employee emps) {
        bool ok = false;
        char name[128];

        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            int k = 0;
            while (read(emps.m_empNo) && read(emps.m_salary) && read(name)) {
                int len_empName = strLen(name);
                emps.m_name = new char[len_empName + 1]; // Allocate memory for name
                strCpy(emps.m_name, name); // Copy name into allocated memory
                employees[k++] = emps; // Store in employees array
            };
            delete[] emps.m_name; // Deallocate temporary name memory
            ok = true;
        }
        return ok;
    }

    // Function to load all employee records from the file
    bool load() {
        bool ok = false;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (int i = 0; i < noOfEmployees; i++) {
                if (read(employees[i].m_empNo) && read(employees[i].m_salary)) {
                    employees[i].m_name = new char[100]; // Dynamically allocate memory for name
                    read(employees[i].m_name); // Read name
                }
            }
            ok = true;
            closeFile(); // Close file to avoid memory leak
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // Function to display employee information
    void display(Employee* emps) {
        for (int j = 0; j < noOfEmployees; j++) {
            cout << emps[j].m_empNo << ": " << emps[j].m_name << ", " << emps[j].m_salary << endl;
        }
        delete[] emps; // Deallocate memory for employees
    }

    // Function to display all employees
    void display() {
        if (employees) {
            sort(); // Sort employees by employee number
            cout << "Employee Salary report, sorted by employee number\n"
                << "no- Empno, Name, Salary\n"
                << "------------------------------------------------\n";
            for (int j = 0; j < noOfEmployees; j++) {
                cout << j + 1 << "- " << employees[j].m_empNo << ": " << employees[j].m_name << ", " << employees[j].m_salary << endl;
            }
        }
    }

    // Function to deallocate memory allocated for employees
    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name; // Deallocate memory for each name
        }
        delete[] employees; // Deallocate memory for employee array
    }

} // End of namespace sdds
