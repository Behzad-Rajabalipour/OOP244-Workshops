#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Rectangle.h"
#include "string.h"

using namespace std;

namespace sdds {
    // Constructor for Rectangle
    Rectangle::Rectangle(const char* label_, int _width, int height_) : LblShape(label_) {
        // Calculate the minimum width required to fit the label
        int cmpWidth = strlen(LblShape::label()) + 2;

        // Check if provided width and height are valid
        if (_width > cmpWidth && height_ > 3) {
            m_width = _width;
            m_height = height_;
        }
    }

    // Read specifications for Rectangle from input stream
    void Rectangle::getSpecs(istream& in) {
        int width, height;
        char comma;
        bool flag = false;

        while (!flag) {
            // Read specifications for the label (base class)
            LblShape::getSpecs(in);

            // Read width, comma, and height
            in >> width >> comma >> height;
            if (!in) {
                in.clear();
                in.ignore(32767, '\n'); // Clear input and ignore until newline on error
            }
            else {
                in.ignore(); // Ignore newline character
                m_width = width;
                m_height = height;
                flag = true;
            }
        }
    }

    // Draw the Rectangle on the output stream
    void Rectangle::draw(ostream& os) const {
        if (m_width > 0 && m_height > 0) {
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+' << endl;

            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os << left << LblShape::label() << "|" << endl;

            for (unsigned int i = 0; i < (m_height - 3); i++) {
                os << '|';
                os.width(m_width - 2);
                os.fill(' ');
                os << ' ' << '|' << endl;
            }
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+';
        }
    }
}
