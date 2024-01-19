#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds {
    // Overloaded output operator for Streamable objects
    ostream& operator<<(ostream& ostr, const Streamable& ob1) {
        if (ob1) {
            ob1.write(ostr); // If the object is valid, invoke the write function
        }
        return ostr;
    }

    // Overloaded input operator for Streamable objects
    istream& operator>>(istream& istr, Streamable& ob1) {
        return (ob1.read(istr)); // Invoke the read function for input
    }
} // namespace sdds
