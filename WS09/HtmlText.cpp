#include <iostream>
#include "HtmlText.h"
#include "cstring.h"

using namespace std;

namespace sdds {
    // Constructor with filename and title parameters
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
        // Initialize m_title if a valid title is provided
        if (title) {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
    }

    // Copy constructor
    HtmlText::HtmlText(const HtmlText& ob1) {
        *this = ob1; // Call the copy assignment operator to perform copy
    }

    // Copy assignment operator
    HtmlText& HtmlText::operator=(const HtmlText& ob1) {
        if (this != &ob1) {
            // Call the base class (Text) copy assignment operator
            (Text&)*this = (Text&)ob1; // Perform the base class copy assignment
            // Clean up existing m_title
            if (m_title) {
                delete[] m_title;
                m_title = nullptr;
            }
            // Copy m_title from ob1 if it exists
            if (ob1.m_title) {
                m_title = new char[strLen(ob1.m_title) + 1];
                strCpy(m_title, ob1.m_title);
            }
        }
        return *this;
    }

    // Destructor
    HtmlText::~HtmlText() {
        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }
    }

    // Write HTML content to ostream
    void HtmlText::write(ostream& os) const {
        os << "<html><head><title>";
        os << ((m_title != nullptr) ? m_title : "No title");
        os << "</title></head>\n<body>\n";

        int i = 0;
        char temp_ch;
        bool flag = false;
        if (m_title) {
            os << "<h1>" << m_title << "</h1>\n";
            while (Text::operator[](i) != '\0') {
                temp_ch = operator[](i);
                switch (temp_ch) {
                    case ' ':
                        if (flag) os << "&nbsp;";
                        else {
                            os << temp_ch;
                            flag = true;
                        }
                        break;
                    case '<':
                        os << "&lt;";
                        flag = false;
                        break;
                    case '>':
                        os << "&gt;";
                        flag = false;
                        break;
                    case '\n':
                        os << "<br />\n";
                        flag = false;
                        break;
                    default:
                        os << temp_ch;
                        flag = false;
                        break;
                }
                i++;
            }
        }
        os << "</body>\n</html>";
    }
}
