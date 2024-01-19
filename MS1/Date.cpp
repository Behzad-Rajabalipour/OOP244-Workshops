// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "iomanip"
using namespace std;
#include "Date.h"
namespace sdds {
    // validate checks if m_year, m_mon, m_day are valid and returns 1 if valid, 0 if not
    bool Date::validate() {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }

    // Calculate the number of days in the current month considering leap years
    int Date::mdays() const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }

    // Get the current system year
    int Date::systemYear() const {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        return lt.tm_year + 1900;
    }

    // Set the Date object to the current date
    void Date::setToToday() {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        m_day = lt.tm_mday;
        m_mon = lt.tm_mon + 1; // tm_mon is 0-based
        m_year = lt.tm_year + 1900;
        errCode(NO_ERROR);
    }

    // Calculate the number of days since 0001/01/01
    int Date::daysSince0001_1_1() const {
        int year = m_year;
        int month = m_mon;
        if (month < 3) {
            year--;
            month += 12;
        }
        return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + m_day - 306;
    }

    // Getter function for daysSince0001_1_1
    int Date::daysSince0001_1_1_getter() const {
        return daysSince0001_1_1();
    }

    // Default constructor that sets the Date object to the current date
    Date::Date() : m_CUR_YEAR(systemYear()) {
        setToToday();
    }

    // Constructor that creates a Date object with assigned values and validates it
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }

    // Function to get the status message corresponding to the error code
    const char* Date::dateStatus() const {
        return DATE_ERROR[errCode()];
    }

    // Function to get the current system year
    int Date::currentYear() const {
        return m_CUR_YEAR;
    }

    // Setter for error code
    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }

    // Getter for error code
    int Date::errCode() const {
        return m_ErrorCode;
    }

    // Check if the Date object has a validation error
    bool Date::bad() const {
        return m_ErrorCode != 0;
    }

    // Read function to input a Date object
    istream& Date::read(istream& istr) {
        errCode(NO_ERROR);

        // Input format: yyyy/mm/dd
        istr >> m_year;
        istr.ignore(); // Ignore the delimiter '/'
        istr >> m_mon;
        istr.ignore(); // Ignore the delimiter '/'
        istr >> m_day;

        // Check if the input stream has failed
        if (!istr) {
            istr.clear(); // Clear the fail bit
            istr.ignore(1000, '\n'); // Ignore any remaining characters on the line
            errCode(CIN_FAILED); // Set the error code to indicate a failed input
        }
        else {
            validate(); // Validate the Date object
        }

        return istr;
    }

    // Write function to output a Date object
    ostream& Date::write(ostream& ostr) const {
        if (bad()) {
            ostr << dateStatus(); // Output the error message if there is an error
        }
        else {
            // Output the Date object in the format yyyy/mm/dd
            ostr << m_year << "/"
                << setw(2) << right << setfill('0') << m_mon << "/"
                << setw(2) << right << setfill('0') << m_day;
        }
        return ostr;
    }

    //-----------------------------------------------------------------------------------------
    // External operators: << and >> for Date
    istream& operator>>(istream& istr, Date& RO) {
        return RO.read(istr);
    }

    ostream& operator<<(ostream& ostr, const Date& RO) {
        return RO.write(ostr);
    }

    // Comparison operators for Date objects
    bool operator>=(const Date& ob1, const Date& ob2) {
        return (ob1.daysSince0001_1_1_getter() >= ob2.daysSince0001_1_1_getter());
    }

    bool operator<=(const Date& ob1, const Date& ob2) {
        return (ob1.daysSince0001_1_1_getter() <= ob2.daysSince0001_1_1_getter());
    }

    bool operator<(const Date& ob1, const Date& ob2) {
        return ob1.daysSince0001_1_1_getter() < ob2.daysSince0001_1_1_getter();
    }

    bool operator>(const Date& ob1, const Date& ob2) {
        return ob1.daysSince0001_1_1_getter() > ob2.daysSince0001_1_1_getter();
    }

    int operator-(const Date& ob1, const Date& ob2) {
        return (ob1.daysSince0001_1_1_getter() - ob2.daysSince0001_1_1_getter());
    }

    // Conversion operator to check if a Date object is valid
    Date::operator bool() const {
        return (!bad());
    }

    // Equality operator for Date objects
    bool Date::operator==(const Date& ob2) const {
        return (daysSince0001_1_1() == ob2.daysSince0001_1_1());
    }

    // Inequality operator for Date objects
    bool Date::operator!=(const Date& ob2) const {
        return (daysSince0001_1_1() != ob2.daysSince0001_1_1());
    }
}
