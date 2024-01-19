#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds {
    class Shape {
    public:
        virtual ~Shape() {}; // Virtual destructor, used for polymorphism when deleting derived objects. #ref3
        virtual void draw(std::ostream&) const = 0; // Pure virtual function for drawing the shape. Must be implemented by derived classes. #ref2
        virtual void getSpecs(std::istream&) = 0; // Pure virtual function for getting shape specifications. Must be implemented by derived classes.
    }; // End of Shape class

    std::ostream& operator<<(std::ostream&, const Shape&); // Overloaded output operator for shape objects. #ref1

    std::istream& operator>>(std::istream&, Shape&); // Overloaded input operator for shape objects.
} // End of namespace sdds

#endif // !SDDS_SHAPE_H
