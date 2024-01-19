#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds {
    // Default constructor: Initializes mark to zero
    Mark::Mark() {
        value = 0;
    }

    // Constructor with parameter: Initializes mark with the given value if valid
    Mark::Mark(int value_) {
        if (0 <= value_ && value_ <= 100)
            value = value_;
        else
            value = 0;  // Setting to zero if the value is invalid
    }

    // Conversion to int: Returns the raw mark value or 0 if invalid
    Mark::operator int() const {
        if (0 <= value && value <= 100) {
            return value;
        }
        else
            return 0;
    }

    // Conversion to double: Returns a double value based on the mark range
    Mark::operator double() const {
        if (0 <= value && value < 50)
            return 0;  // Failing grade
        else if (50 <= value && value < 60)
            return 1;  // D grade
        else if (60 <= value && value < 70)
            return 2;  // C grade
        else if (70 <= value && value < 80)
            return 3;  // B grade
        else if (80 <= value && value <= 100)
            return 4;  // A grade
        else
            return 0;  // Invalid mark
    }

    // Conversion to char: Returns a letter grade based on the mark range
    Mark::operator char() const {
        if (0 <= value && value < 50)
            return 'F';
        else if (50 <= value && value < 60)
            return 'D';
        else if (60 <= value && value < 70)
            return 'C';
        else if (70 <= value && value < 80)
            return 'B';
        else if (80 <= value && value <= 100)
            return 'A';
        else
            return 'X';  // Invalid mark
    }

    // Addition assignment: Adds value to the mark if the result is within valid range
    int Mark::operator+=(int value_) {
        if (0 <= value + value_ && value + value_ <= 100 && 0 <= value && value <= 100) {
            this->value += value_;
            return value;
        }
        value = 0;  // Setting to zero if the result is invalid
        return 0;
    }

    // Friend function: Adds the mark's value to an integer
    int operator+=(int& value, Mark& ob1) {
        value += ob1.valueGetter();  // Using getter method to access the private member
        return value;
    }

    // Assignment operator: Sets the mark to the given value if valid
    int Mark::operator=(int value_) {
        if (0 <= value_ && value_ <= 100) {
            value = value_;
            return value;
        }
        value = 0;  // Setting to zero if the value is invalid
        return 0;
    }

    // Getter function: Returns the raw mark value
    int Mark::valueGetter() {
        return value;
    }

}  // end of namespace sdds
