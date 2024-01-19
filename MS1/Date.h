#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>

namespace sdds {
   // Error codes for Date class
   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int DAY_ERROR = 4;

   // Error messages corresponding to error codes
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

      // Private member function to calculate the number of days since 0001/1/1
      int daysSince0001_1_1()const;

      // Private member function to validate the date
      bool validate();

      // Private member function to set the error code
      void errCode(int);

      // Private member function to get the current system year
      int systemYear()const;

      // Private member function to check if the date is invalid
      bool bad()const;

      // Private member function to get the number of days in the current month
      int mdays()const;

      // Private member function to set the date to the current system date
      void setToToday();
   public:
      // Constructors
      Date();

      // Constructor with parameters
      Date(int year, int mon, int day);

      // Read function to input a date
      std::istream& read(std::istream& = std::cin);

      // Write function to output a date
      std::ostream& write(std::ostream& = std::cout)const;

      // Getter function to get the error code
      int errCode()const;

      // Getter function to get the status of the date as a string
      const char* dateStatus()const;

      // Getter function to get the current year
      int currentYear()const;

      // Conversion operator to check if the date is valid
      operator bool() const;

      // Getter function to get the number of days since 0001/1/1
      int daysSince0001_1_1_getter()const;

      // Comparison operators for Date objects
      bool operator==(const Date& ob2)const;
      bool operator!=(const Date& ob2)const;
   };

   // Input operator for Date objects
   std::istream& operator>>(std::istream& istr, Date& RO);

   // Output operator for Date objects
   std::ostream& operator<<(std::ostream& ostr, const Date& RO);         
  
   // Comparison operators for Date objects
   bool operator>=(const Date& ob1,const Date& ob2);
   bool operator<=(const Date& ob1, const Date& ob2);
   bool operator<(const Date& ob1,const Date& ob2);
   bool operator>(const Date& ob1, const Date& ob2);

   // Subtraction operator to find the difference in days between two Date objects
   int operator-(const Date& ob1,const Date& ob2);      
}
#endif
