// Final Project Milestone 1
// Date Module
// File    Date.h
// Version 1.0
// Author  Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>

namespace sdds {
    // Global constants and error codes
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

    class Date {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;

        // Private member functions
        int daysSince0001_1_1() const;  // returns number of days passed since the date 0001/1/1
        bool validate();                // validates the date, setting the error code, and returning true if valid, false if invalid
        void setToToday();              // sets the date to the current date (system date)
        void errCode(int);              // sets the error code
        int systemYear() const;         // returns the current system year
        bool bad() const;               // returns true if there's an error
        int mdays() const;              // returns the number of days in the current month

    public:
        // Constructors
        Date();                        // creates a date with the current date
        Date(int year, int mon, int day); // creates a date with assigned values, then validates the date and sets the error code accordingly

        // Member functions
        std::istream& read(std::istream& istr = std::cin);  // input: istream, output: istream; allows user to input date
        std::ostream& write(std::ostream& ostr = std::cout) const; // input: ostream, output: ostream; displays the date

        int errCode() const;           // returns the error code or zero if the date is valid
        const char* dateStatus() const;// returns a string corresponding to the current status of the date
        int currentYear() const;       // returns the m_CUR_YEAR value
        operator bool() const;         // conversion to bool; checks if the date is valid
        int daysSince0001_1_1_getter() const; // returns the days since 0001/1/1

        // Comparison operators
        bool operator==(const Date& ob2) const;
        bool operator!=(const Date& ob2) const;

    };

    // Input and output operators for Date class
    std::istream& operator>>(std::istream& istr, Date& RO);
    std::ostream& operator<<(std::ostream& ostr, const Date& RO);

    // Comparison operators for Date class
    bool operator>=(const Date& ob1, const Date& ob2);
    bool operator<=(const Date& ob1, const Date& ob2);
    bool operator<(const Date& ob1, const Date& ob2);
    bool operator>(const Date& ob1, const Date& ob2);
    int operator-(const Date& ob1, const Date& ob2);

    // Truly global variables
    extern bool sdds_test;  // this keyword "extern" is used to declare a variable or function that is defined in another source file.
    extern int sdds_year;   // Usually, extern is placed in a header file, and the actual variable or function is declared in a source file.
    extern int sdds_mon;    
    extern int sdds_day;


}  // namespace sdds

#endif
