#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds {
    class Line : public LblShape {
        unsigned int m_length = 0; // Length of the line.
    public:
        Line() {}; // Default constructor.
        Line(const char*, int); // Constructor with parameters for label and length.
        ~Line() {}; // Destructor.

        void getSpecs(std::istream& istr); // Function to get line specifications from input.
        void draw(std::ostream&) const; // Function to draw the line.
    };
}

#endif // !SDDS_LINE_H_
