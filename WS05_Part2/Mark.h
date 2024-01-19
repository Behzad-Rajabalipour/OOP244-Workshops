#ifndef SDDS_MARK_H_  // Header guard to prevent multiple inclusions
#define SDDS_MARK_H_

namespace sdds {
    // Class Mark to handle student marks
    class Mark {
        int value = -1;  // Private data member to store the mark value, initialized to -1

    public:
        // Constructors
        Mark();  // Default constructor
        Mark(int);  // Constructor that accepts an integer value for the mark

        // Getter
        int valueGetter();  // Getter function to access the private mark value

        // Conversion operators
        operator int()const;  // Conversion operator to convert Mark to an int
        operator double()const;  // Conversion operator to convert Mark to a double (e.g., GPA)
        operator char()const;  // Conversion operator to convert Mark to a char (e.g., letter grade)

        // Operators
        int operator+=(int);  // Operator to add an integer to a Mark object and return the new value
        friend int operator+=(int&, Mark&);  // Friend operator to add Mark's value to an integer
        int operator=(int);  // Assignment operator to assign an integer to a Mark object
    };

}
#endif  // End of header guard
