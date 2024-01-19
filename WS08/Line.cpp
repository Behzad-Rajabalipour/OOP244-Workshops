#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds {
    // Constructor for Line
    Line::Line(const char* label_, int _length) : LblShape(label_) {
        // Check if the provided length is valid
        if (_length > 0)
            m_length = _length;
    }

    // Read specifications for Line from input stream
    void Line::getSpecs(istream& in) {
        int len;
        for (int i = 0;; i++) {
            // Read specifications for the label (base class)
            LblShape::getSpecs(in);

            // Read length separated by ',' from input
            in >> len;
            if (!in) {
                in.clear();
                in.ignore(32767, '\n'); // Clear input and ignore until newline on error
            }
            else {
                in.ignore(); // Ignore newline character
                m_length = len;
                break;
            }
        }
    }

    // Draw the Line on the output stream
    void Line::draw(ostream& os) const {
        if (m_length > 0 && label()) {
            os << label() << endl; // Output the label (base class)
            os.width(m_length);   // Set the width to match the length and fill with '='
            os.fill('=');
            os << '=';
        }
    }
}
