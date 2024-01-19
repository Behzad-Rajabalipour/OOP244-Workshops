#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "iomanip"
using namespace std;
#include "Date.h"

namespace sdds {
   // Function to validate the date
   bool Date::validate() {
      errCode(NO_ERROR);
      // Check if the year is within a valid range
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      // Check if the month is valid (between 1 and 12)
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      // Check if the day is valid for the current month
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }

   // Function to calculate the number of days in the current month
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }

   // Function to get the current system year
   int Date::systemYear()const {
      time_t t = time(NULL);    
      tm lt = *localtime(&t);   
      return lt.tm_year + 1900; 
   }

   // Function to set the date to the current system date
   void Date::setToToday() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;       
      m_mon = lt.tm_mon + 1;           
      m_year = lt.tm_year + 1900;      
      errCode(NO_ERROR);
   }

   // Function to calculate the number of days since 0001-01-01
   int Date::daysSince0001_1_1()const { 
      int year = m_year;
      int month = m_mon;
      if (month < 3) {
         year--;
         month += 12;
      }
      return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + m_day - 306;
   }

   // Getter for daysSince0001_1_1
   int Date::daysSince0001_1_1_getter()const {
       return daysSince0001_1_1();
   }

   // Default constructor for Date class
   Date::Date() :m_CUR_YEAR(systemYear()) {                     
      setToToday();
   }

   // Constructor with date components for Date class
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {  
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }

   // Function to get the date status
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];    
   }

   // Function to get the current year
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }

   // Setter for error code
   void Date::errCode(int readErrorCode) {    
      m_ErrorCode = readErrorCode;
   }

   // Getter for error code
   int Date::errCode()const {            
      return m_ErrorCode;
   }

   // Function to check if the date is valid
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }

   // Function to read a date from input
   istream& Date::read(istream& istr) {
       errCode(NO_ERROR);

       istr >> m_year;
       istr.ignore();
       istr >> m_mon;
       istr.ignore();
       istr >> m_day;

       if (!istr) {  
           istr.clear();
           istr.ignore(1000, '\n');
           errCode(CIN_FAILED);     
       }
       else {
           validate();                    
       }

       return istr;
   }

   // Function to write the date to output
   ostream& Date::write(ostream& ostr) const{           
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

   //-----------------------------------------------------------------------------------------

   // Overloaded input operator for Date class
   istream& operator>>(istream& istr, Date& RO) {
      return RO.read(istr);
   }

   // Overloaded output operator for Date class
   ostream& operator<<(ostream& ostr, const Date& RO) {
      return RO.write(ostr);
   }

   // Comparison operators for Date class
   bool operator>=(const Date& ob1,const Date& ob2) {
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

   // Conversion operator to bool for Date class
   Date::operator bool() const{
       return (!bad());         
   }

   // Equality operator for Date class
   bool Date::operator==(const Date& ob2) const{
       return (daysSince0001_1_1() == ob2.daysSince0001_1_1());
   }

   // Inequality operator for Date class
   bool Date::operator!=(const Date& ob2) const {
       return (daysSince0001_1_1() != ob2.daysSince0001_1_1());
   }
}
