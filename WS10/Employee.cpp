#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Employee.h"

namespace sdds {
    // Default constructor
    Employee::Employee() {
        set(0, "", 0.0, 0);
    }

    // Parameterized constructor
    Employee::Employee(int stno, const char* name, double salary, int office) {
        set(stno, name, salary, office);
    }

    // Setter function to set employee information
    void Employee::set(int stno, const char* name, double salary, int office) {
        m_empno = stno;
        strcpy(m_name, name);
        m_salary = salary;
        m_office = office;
    }

    // Display function to show employee information
    ostream& Employee::display(ostream& os) const {
        return os << m_empno << " " << m_name << " (Office# " << m_office << ") Salary: $" << setprecision(2) << fixed << m_salary;
    }

    // Read function to read employee information from input
    istream& Employee::read(istream& is) {
        is >> m_empno;
        is.getline(m_name, 40, ',');
        is >> m_salary;
        return is;
    }

    // Operator overload to check if employee's office matches a given office number
    bool Employee::operator==(int office) const {
        return m_office == office;
    }
}
