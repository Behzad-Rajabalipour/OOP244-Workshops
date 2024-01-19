#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__

#include "Text.h"

namespace sdds {
    class HtmlText : public Text {
        char* m_title = nullptr; // Pointer to store the HTML title
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr); // Constructor with optional filename and title parameters
        HtmlText(const HtmlText&); // Copy constructor
        HtmlText& operator=(const HtmlText&); // Copy assignment operator
        ~HtmlText(); // Destructor

        void write(std::ostream&) const; // Function to write HTML content to an output stream
    };
}

#endif // !SDDS_HTMLTEXT_H__
