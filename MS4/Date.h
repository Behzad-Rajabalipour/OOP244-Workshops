// Header guard to prevent multiple inclusions
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__

#include <iostream>

namespace sdds {
    // Global variables for error codes and messages
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
        "No Error",
        "cin Failed",
        "Bad Year Value",
        "Bad Month Value",
        "Bad Day Value"
    };
    const int MIN_YEAR = 1500;

    // Date class declaration
    class Date {
    private:
        int m_year;           // Year component of the date
        int m_mon;            // Month component of the date
        int m_day;            // Day component of the date
        int m_ErrorCode;      // Error code for the last validation
        int m_CUR_YEAR;       // Current year (system year)

        // Private member functions
        int daysSince0001_1_1() const; // Calculate total days since 0001/01/01
        bool validate();                // Validate the date components
        void setToToday();              // Set the date to the current system date
        void errCode(int);              // Set the error code
        int systemYear() const;         // Get the current system year
        bool bad() const;               // Check if there is an error
        int mdays() const;              // Get the number of days in the current month

    public:
        // Constructors
        Date();                        // Default constructor
        Date(int year, int mon, int day); // Parameterized constructor

        // Member functions
        std::istream& read(std::istream & = std::cin);   // Read date from input stream
        std::ostream& write(std::ostream & = std::cout) const; // Write date to output stream
        int errCode() const;            // Get the error code
        const char* dateStatus() const; // Get the date status message
        int currentYear() const;        // Get the current system year
        operator bool() const;          // Check if the date is valid
        int daysSince0001_1_1_getter() const; // Get total days since 0001/01/01
        bool operator==(const Date& ob2) const; // Compare dates for equality
        bool operator!=(const Date& ob2) const; // Compare dates for inequality
    };

    // Stream operators overloads
    std::istream& operator>>(std::istream& istr, Date& RO); // Input stream operator
    std::ostream& operator<<(std::ostream& ostr, const Date& RO); // Output stream operator

    // Comparison operators overloads
    bool operator>=(const Date& ob1, const Date& ob2); // Greater than or equal to
    bool operator<=(const Date& ob1, const Date& ob2); // Less than or equal to
    bool operator<(const Date& ob1, const Date& ob2);  // Less than
    bool operator>(const Date& ob1, const Date& ob2);  // Greater than

    // Subtraction operator overload
    int operator-(const Date& ob1, const Date& ob2);    // Date subtraction

    // Truly global variables (extern declared)
    extern bool sdds_test; // Defined in ms3_tester.cpp
    extern int sdds_year;  // Defined in Date.cpp 
    extern int sdds_mon;
    extern int sdds_day;

} // namespace sdds

#endif // SDDS_DATE_H__
