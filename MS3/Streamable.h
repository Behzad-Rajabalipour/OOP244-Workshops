#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

using namespace std;

namespace sdds {
	class Streamable {
	public:
		// Pure virtual functions for stream operations
		virtual ostream& write(ostream & = cout) const = 0;  // Pure virtual function for writing to output stream
		virtual istream& read(istream & = cin) = 0;         // Pure virtual function for reading from input stream
		virtual bool conIO(ios&) const = 0;                // Pure virtual function for checking I/O status
		virtual operator bool() const = 0;                 // Pure virtual function for boolean conversion
		virtual ~Streamable() {};                          // Virtual destructor for proper cleanup

	};

	// Global stream operators for Streamable class
	ostream& operator<<(ostream&, const Streamable&);  // Output stream operator
	istream& operator>>(istream&, Streamable&);        // Input stream operator
}

#endif // !SDDS_STREAMABLE_H_
