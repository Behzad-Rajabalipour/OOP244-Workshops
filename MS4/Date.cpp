#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "iomanip"
#include "Date.h"

using namespace std;

namespace sdds {
    // Global variables
    bool sdds_test = false;          // Indicate whether testing mode is active
    int sdds_year = 2023;            // Default year
    int sdds_mon = 12;                // Default month
    int sdds_day = 25;                // Default day

    // Check if the date is valid
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

    // Calculate the number of days in a month
    int Date::mdays() const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }

    // Get the system year
    int Date::systemYear() const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }

    // Set the date to the current date
    void Date::setToToday() {
        if (sdds_test) {
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;   // month +1
            m_year = lt.tm_year + 1900;  // year +1900
        }
        errCode(NO_ERROR);
    }

    // Calculate the number of days since 0001-01-01
    int Date::daysSince0001_1_1() const {
        int year = m_year;
        int month = m_mon;
        if (month < 3) {
            year--;
            month += 12;
        }
        return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + m_day - 306;
    }

    // Get the number of days since 0001-01-01
    int Date::daysSince0001_1_1_getter() const {
        return daysSince0001_1_1();
    }

    // Default constructor
    Date::Date() : m_CUR_YEAR(systemYear()) {
        setToToday();
    }

    // Constructor with parameters
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }

    // Get the date status as a string
    const char* Date::dateStatus() const {
        return DATE_ERROR[errCode()];
    }

    // Get the current year
    int Date::currentYear() const {
        return m_CUR_YEAR;
    }

    // Set the error code
    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }

    // Get the error code
    int Date::errCode() const {
        return m_ErrorCode;
    }

    // Check if there is an error
    bool Date::bad() const {
        return m_ErrorCode != 0;
    }

    // Read date from the input stream
    istream& Date::read(istream& istr) {
        errCode(NO_ERROR);

        istr >> m_year;
        istr.ignore();
        istr >> m_mon;
        istr.ignore();
        istr >> m_day;

        if (!istr) {
            errCode(CIN_FAILED);
        }
        else {
            validate();
        }

        return istr;
    }

    // Write date to the output stream
    ostream& Date::write(ostream& ostr) const {
        if (bad()) {
            ostr << dateStatus();
        }
        else {
            ostr << m_year << "/"
                << setw(2) << right << setfill('0') << m_mon << "/"
                << setw(2) << right << setfill('0') << m_day;
        }
        return ostr;
    }

    // Overloaded stream extraction operator
    istream& operator>>(istream& istr, Date& RO) {
        return RO.read(istr);
    }

    // Overloaded stream insertion operator
    ostream& operator<<(ostream& ostr, const Date& RO) {
        return RO.write(ostr);
    }

    // Comparison operators
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

    // Conversion operator to bool
    Date::operator bool() const {
        return (!bad());
    }

    // Comparison operator for equality
    bool Date::operator==(const Date& ob2) const {
        return (daysSince0001_1_1() == ob2.daysSince0001_1_1());
    }

    // Comparison operator for inequality
    bool Date::operator!=(const Date& ob2) const {
        return (daysSince0001_1_1() != ob2.daysSince0001_1_1());
    }

}  // namespace sdds
