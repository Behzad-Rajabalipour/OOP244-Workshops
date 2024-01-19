#include <iostream>
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "ReadWrite.h"

namespace sdds {
    // Employee class derived from ReadWrite
    class Employee : public ReadWrite {
        int m_empno;         // Employee number
        int m_office;        // Office number
        char m_name[41];     // Employee name
        double m_salary;     // Employee salary

    public:
        // Default constructor
        Employee();

        // Constructor with parameters
        Employee(int empno, const char* name, double salary, int office);

        // Set method to initialize Employee object
        void set(int empno, const char* name, double salary, int office);

        // Virtual function to display employee information
        std::ostream& display(std::ostream& os) const;

        // Virtual function to read employee information
        std::istream& read(std::istream& is);

        // Operator overload for checking if the office number matches
        bool operator==(int office) const;
    };
}
#endif // !SDDS_EMPLOYEE_H_
