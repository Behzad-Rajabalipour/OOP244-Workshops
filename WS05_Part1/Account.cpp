#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;

namespace sdds {
    // Set the account to an empty state
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.00;
    }

    // Default constructor: Initializes an account to default values
    Account::Account() {
        m_number = 0;
        m_balance = 0.00;
    }

    // Constructor with parameters: Initializes account with a number and balance if valid
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999 && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    // Copy constructor: Creates a new account by copying an existing one
    Account::Account(const Account& ob1) {
        m_number = ob1.m_number;
        m_balance = ob1.m_balance;
    }

    // Display the account information
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        } else if (~*this) {
            cout << "  NEW  |         0.00 ";
        } else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    // Cast Account object to bool
    Account::operator bool() const {
        return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
    }

    // Cast Account object to int
    Account::operator int() const {
        return (int)m_number;
    }

    // Cast Account object to double
    Account::operator double() const {
        return (double)m_balance;
    }

    // Check if the account number is empty
    bool Account::operator ~() const {
        return m_number == 0;
    }

    // Assign a new account number if current account is empty
    Account Account::operator=(int number) {
        if (m_number != 0)
            return *this;
        else if (number >= 10000 && number <= 99999)
            m_number = number;
        else
            this->setEmpty();
        return *this;
    }

    // Assign account details from another account object
    Account Account::operator=(Account& ob2) {
        if (isValid() && ob2.isValid() && this != &ob2) {
            m_number = ob2.numberGetter();
            m_balance = ob2.balanceGetter();
            ob2.m_number = 0; // Set the ob2 to new Account
            ob2.m_balance = 0.00;
        }
        return *this;
    }

    // Add a balance to the account
    Account Account::operator+=(double balance) {
        if (isValid() && 0 < balance) m_balance += balance;
        return *this;
    }

    // Friend function: Adds account balance to an integer
    int operator+=(int& number, Account& ob1) {
        number += ob1.m_balance;
        return number;
    }

    // Friend function: Adds account balance to a double
    void operator+=(double& number, Account& ob1) {
        number += ob1.m_balance;
    }

    // Subtract a balance from the account
    Account Account::operator-=(double balance) {
        if (isValid() && 0 < balance && m_balance - balance >= 0)
            m_balance -= balance;
        return *this;
    }

    // Check if two accounts are equal
    bool Account::operator==(Account& ob2) {
        return m_number == ob2.numberGetter() && m_balance == ob2.balanceGetter();
    }

    // Transfer balance from one account to another
    Account Account::operator<<(Account& ob2) {
        if (isValid() && ob2.isValid() && !(this == &ob2)) {
            m_balance += ob2.balanceGetter();
            ob2.balanceSetter(0.00);
        }
        return *this;
    }

    // Transfer balance to another account from this one
    Account Account::operator>>(Account& ob2) {
        if (isValid() && ob2.isValid() && !(this == &ob2)) {
            ob2.balanceSetter(m_balance + ob2.balanceGetter());
            m_balance = 0.00;
        }
        return *this;
    }

    // Adds balances of two accounts
    double Account::operator+(const Account& ob2) {
        if (isValid() && ob2.isValid()) {
            return m_balance + ob2.balanceGetter();
        }
        return 0.00;
    }

    // Check if the account is valid
    bool Account::isValid() const {
        return (m_number >= 10000 && m_number <= 99999) || m_number == 0;
    }

    // Get the balance of the account
    double Account::balanceGetter() const {
        return m_balance;
    }

    // Get the account number
    int Account::numberGetter() {
        return m_number;
    }

    // Set the balance of the account
    void Account::balanceSetter(double balance) {
        m_balance = balance;
    }
} // end of namespace sdds
