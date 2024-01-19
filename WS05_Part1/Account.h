#ifndef SDDS_ACCOUNT_H_ // Include guard to prevent multiple inclusions
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    // Account class represents a bank account with basic functionalities
    class Account {
        int m_number; // Account number
        double m_balance; // Account balance

        // Sets the account to an empty or invalid state
        void setEmpty();

        // Validates if the account is in a valid state
        bool isValid() const;

    public:
        // Default constructor
        Account();

        // Constructor that initializes the account with a number and balance
        Account(int number, double balance);

        // Copy constructor
        Account(const Account& ob1);

        // Displays account details
        std::ostream& display()const;

        // Getter for the account balance
        double balanceGetter() const;

        // Setter for the account balance
        void balanceSetter(double);

        // Getter for the account number
        int numberGetter();

        // Conversion operators
        operator bool()const; // Converts account to bool (true if valid)
        operator int()const; // Converts account to int (returns account number)
        operator double()const; // Converts account to double (returns balance)

        // Logical NOT operator (checks if account is in an invalid state)
        bool operator ~() const;

        // Assignment operators
        Account operator=(int); // Assigns a new number to the account
        Account operator=(Account&); // Copy assignment

        // Addition/subtraction operators
        Account operator+=(double); // Adds amount to balance
        Account operator-=(double); // Subtracts amount from balance

        // Friend operators for addition
        friend int operator+=(int&, Account&); // Adds account balance to an int
        friend void operator+=(double&, Account&); // Adds account balance to a double

        // Comparison operator
        bool operator==(Account&);

        // Stream operators for account transfer
        Account operator<<(Account&); // Transfers balance from this to another account
        Account operator>>(Account&); // Transfers balance from another to this account

        // Addition operator for combining balances of two accounts
        double operator+(const Account&);
    };


}
#endif // SDDS_ACCOUNT_H_
