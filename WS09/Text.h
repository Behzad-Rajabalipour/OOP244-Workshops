#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace sdds {
    class Text {
        char* m_filename{ nullptr }; // Pointer to store the filename
        char* m_content = nullptr;   // Pointer to store the content of the text file

        int getFileLength() const;   // Private helper function to get the length of the file
    protected:
        const char& operator[](int index) const; // Protected operator[] for accessing characters in the content
    public:
        Text(const char* filename = nullptr); // Constructor with an optional filename parameter
        Text(const Text&);            // Copy constructor
        Text& operator=(const Text&); // Copy assignment operator
        virtual ~Text();              // Virtual destructor to support polymorphism

        void read(); // Read the content from the file
        virtual void write(std::ostream& os) const; // Virtual function to write content to an output stream
    };

    // Overloaded operator<< for outputting Text objects
    std::ostream& operator<<(std::ostream&, const Text&);
}
#endif // !SDDS_TEXT_H__
