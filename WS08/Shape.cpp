#include <iostream>
#include "Shape.h"

using namespace std;

namespace sdds {
    ostream& operator<<(ostream& ostr, const Shape& ob1) {
        ob1.draw(ostr); // Calls the draw function to display the shape.
        return ostr;
    }

    istream& operator>>(istream& istr, Shape& ob1) {
        ob1.getSpecs(istr); // Calls the getSpecs function to read shape specifications.
        return istr;
    }
}
