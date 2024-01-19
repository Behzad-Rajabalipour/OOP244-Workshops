#include <iostream>
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "ReadWrite.h"

namespace sdds {
    class Student : public ReadWrite {
        int m_stno;            // Student number
        char m_name[41];       // Student name (up to 40 characters)
        double m_gpa;          // GPA (Grade Point Average)

    public:
        Student();  // Default constructor
        Student(int stno, const char* name, double gpa); // Constructor with parameters
        void set(int stno, const char* name, double gpa); // Set student information
        std::ostream& display(std::ostream& os) const; // Display student information
        std::istream& read(std::istream& is); // Read student information from input
        bool operator==(double gpa) const; // Compare student's GPA with a given value
    };
}

#endif // !SDDS_STUDENT_H_
