#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds {
    class Rectangle : public LblShape {
        unsigned int m_width{ 0 }; // Width of the rectangle.
        unsigned int m_height = 0; // Height of the rectangle.
    public:
        Rectangle() {}; // Default constructor.
        Rectangle(const char*, int, int); // Constructor with parameters for label, width, and height.
        ~Rectangle() {}; // Destructor.

        void getSpecs(std::istream&); // Function to get rectangle specifications from input.
        void draw(std::ostream&) const; // Function to draw the rectangle.
    };
}

#endif // !SDDS_RECTANGLE_H_
