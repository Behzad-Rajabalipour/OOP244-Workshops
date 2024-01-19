// Header guard to prevent multiple inclusions
#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

// Standard C++ library headers
using namespace std;

// Namespace declaration
namespace sdds {
    // Streamable class declaration
    class Streamable {
    public:
        // Pure virtual functions for stream operations
        virtual ostream& write(ostream & = cout) const = 0;  // Pure virtual function for writing to the output stream
        virtual istream& read(istream & = cin) = 0;          // Pure virtual function for reading from the input stream
        virtual bool conIO(ios&) const = 0;                 // Pure virtual function to check if IO is connected to console or file
        virtual operator bool() const = 0;                  // Pure virtual conversion operator to bool
        virtual ~Streamable() {};                           // Virtual destructor for polymorphism

    };

    // Global stream operators for Streamable objects
    ostream& operator<<(ostream&, const Streamable&);
    istream& operator>>(istream&, Streamable&);

} // namespace sdds

#endif // !SDDS_STREAMABLE_H_
