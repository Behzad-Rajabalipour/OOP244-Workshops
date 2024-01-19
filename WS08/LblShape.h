#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include "Shape.h"

namespace sdds {
    class LblShape : public Shape {
        char* m_label{ nullptr }; // Pointer to the label.
    protected:
        const char* label() const; // Getter function for the label.
    public:
        LblShape() {}; // Default constructor.
        LblShape(const char*); // Constructor with parameter for the label.
        ~LblShape(); // Destructor.

        void getSpecs(std::istream&); // Function to get shape specifications from input.
    };
}

#endif // !SDDS_LBLSHAPE_H_
