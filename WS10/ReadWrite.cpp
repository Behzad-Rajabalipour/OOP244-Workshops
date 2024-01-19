#include <iostream>
#include "ReadWrite.h"
using namespace std;

namespace sdds {
    // Overloaded output operator
    ostream& operator<<(ostream& os, const ReadWrite& c) {
        // Calls the display function of the derived class (polymorphism)
        return c.display(os);
    }

    // Overloaded input operator
    istream& operator>>(istream& is, ReadWrite& c) {
        // Calls the read function of the derived class (polymorphism)
        return c.read(is);
    }
}
