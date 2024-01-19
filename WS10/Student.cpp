#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Student.h"

namespace sdds {
   // Default constructor
   Student::Student() {
      // Initialize student information with default values
      set(0, "", 0.0);
   }

   // Constructor with parameters
   Student::Student(int stno, const char* name, double gpa) {
      // Initialize student information with provided values
      set(stno, name, gpa);
   }

   // Set student information
   void Student::set(int stno, const char* name, double gpa) {
      m_stno = stno;              // Set student number
      strcpy(m_name, name);       // Copy the student name (up to 40 characters)
      m_gpa = gpa;                // Set the GPA
   }

   // Display student information
   ostream& Student::display(ostream& os) const {
      // Display student information in the specified format
      return os << m_stno << " " << m_name << " GPA: " << fixed << setprecision(1) << m_gpa;
   }

   // Read student information from input
   istream& Student::read(istream& is) {
      // Read student number
      is >> m_stno;
      // Read the student name (up to 40 characters)
      is.getline(m_name, 40, '\n');
      return is;
   }

   // Compare student's GPA with a specified value
   bool Student::operator==(double gpa) const {
      // Check if the student's GPA is within a small range of the specified value
      return m_gpa > (gpa - 0.001) && m_gpa < (gpa + 0.001);
   }
}
