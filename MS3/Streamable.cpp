#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds {
	// Overloaded stream insertion operator for Streamable objects
	ostream& operator<<(ostream& ostr, const Streamable& ob1) {
		// Check if the object is valid before writing to the stream
		if (ob1) {
			ob1.write(ostr);
		}
		return ostr;
	}

	// Overloaded stream extraction operator for Streamable objects
	istream& operator>>(istream& istr, Streamable& ob1) {
		// Read from the stream using the read member function of the Streamable object
		return (ob1.read(istr));
	}
}
