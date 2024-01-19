#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "iomanip"
#include "Date.h"

using namespace std;

namespace sdds {
    // Global variables
    bool sdds_test = false;          // Flag for testing purposes (Date.h => #ref3)
    int sdds_year = 2023;            // Default year for testing
    int sdds_mon = 12;                // Default month for testing
    int sdds_day = 25;                // Default day for testing

    bool Date::validate() {
        errCode(NO_ERROR);
        // Check if the year, month, and day values are within valid ranges
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

    int Date::mdays() const {
        // Array representing the number of days in each month
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        // Calculate the number of days in the specified month
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }

    int Date::systemYear() const {
        int theYear = sdds_year;
        // If not in testing mode, get the current system year
        if (!sdds_test) {
            time_t t = time(NULL);            // Get current time as time_t object
            tm lt = *localtime(&t);           // Convert time_t to tm structure
            theYear = lt.tm_year + 1900;      // Extract the year from tm structure
        }
        return theYear;
    }

    void Date::setToToday() {
        if (sdds_test) {
            // Set the date to the predefined testing date
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            // Get the current system date
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            // Set the date to the current system date
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;           // Month is zero-based in tm structure
            m_year = lt.tm_year + 1900;      // Year is the number of years since 1900
        }
        errCode(NO_ERROR);
    }

    int Date::daysSince0001_1_1() const {
        int year = m_year;
        int month = m_mon;
        // Adjust the year and month if the month is before March
        if (month < 3) {
            year--;
            month += 12;
        }
        // Calculate the number of days since 0001-01-01
        return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + m_day - 306;
    }

    int Date::daysSince0001_1_1_getter() const {
        return daysSince0001_1_1();
    }

    Date::Date() : m_CUR_YEAR(systemYear()) {
        // Constructor sets the date to today's date
        setToToday();
    }

    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        // Constructor sets the date to the specified values and validates it
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }

    const char* Date::dateStatus() const {
        // Return a string representing the current error status
        return DATE_ERROR[errCode()];
    }

    int Date::currentYear() const {
        // Return the current system year
        return m_CUR_YEAR;
    }

    void Date::errCode(int readErrorCode) {
        // Set the error code
        m_ErrorCode = readErrorCode;
    }

    int Date::errCode() const {
        // Return the current error code
        return m_ErrorCode;
    }

    bool Date::bad() const {
        // Check if there is an error
        return m_ErrorCode != 0;
    }

    istream& Date::read(istream& istr) {
        errCode(NO_ERROR);
        // Read the year, month, and day from the input stream
        istr >> m_year;
        istr.ignore();
        istr >> m_mon;
        istr.ignore();
        istr >> m_day;

        if (!istr) {
            // If the input stream is in a fail state, set the error code
            errCode(CIN_FAILED);
        }
        else {
            // Validate the entered date
            validate();
        }

        return istr;
    }

    ostream& Date::write(ostream& ostr) const {
        // Write the date to the output stream
        if (bad()) {
            // If there is an error, write the error status
            ostr << dateStatus();
        }
        else {
            // Otherwise, write the date in the specified format
            ostr << m_year << "/"
                << setw(2) << right << setfill('0') << m_mon << "/"
                << setw(2) << right << setfill('0') << m_day;
        }
        return ostr;
    }

    //-----------------------------------------------------------------------------------------

    istream& operator>>(istream& istr, Date& RO) {
        // Input stream operator for Date class
        return RO.read(istr);
    }

    ostream& operator<<(ostream& ostr, const Date& RO) {
        // Output stream operator for Date class
        return RO.write(ostr);
    }

    bool operator>=(const Date& ob1, const Date& ob2) {
        // Comparison operator: greater than or equal to
        return (ob1.daysSince0001_1_1_getter() >= ob2.daysSince0001_1_1_getter());
    }

    bool operator<=(const Date& ob1, const Date& ob2) {
        // Comparison operator: less than or equal to
        return (ob1.daysSince0001_1_1_getter() <= ob2.daysSince0001_1_1_getter());
    }

    bool operator<(const Date& ob1, const Date& ob2) {
        // Comparison operator: less than
        return ob1.daysSince0001_1_1_getter() < ob2.daysSince0001_1_1_getter();
    }

    bool operator>(const Date& ob1, const Date& ob2) {
        // Comparison operator: greater than
        return ob1.daysSince0001_1_1_getter() > ob2.daysSince0001_1_1_getter();
    }

    int operator-(const Date& ob1, const Date& ob2) {
        // Subtraction operator: calculate the difference in days between two dates
        return (ob1.daysSince0001_1_1_getter() - ob2.daysSince0001_1_1_getter());
    }

    //-----------------------------------------------------------------------------------------

    Date::operator bool() const {
        // Boolean conversion operator: check if there is no error
        return (!bad());
    }

    bool Date::operator==(const Date& ob2) const {
        // Equality operator: check if two dates are equal
        return (daysSince0001_1_1() == ob2.daysSince0001_1_1());
    }

    bool Date::operator!=(const Date& ob2) const {
        // Inequality operator: check if two dates are not equal
        return (daysSince0001_1_1() != ob2.daysSince0001_1_1());
    }
}
