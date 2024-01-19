#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_

namespace sdds {
    // Abstract base class for Read and Write operations
    class ReadWrite {
    public:
        // Pure virtual function to display information (must be implemented in derived classes)
        virtual std::ostream& display(std::ostream& os) const = 0;

        // Pure virtual function to read information (must be implemented in derived classes)
        virtual std::istream& read(std::istream& is) = 0;

        // Virtual destructor (must be virtual since this is a base class with virtual functions)
        virtual ~ReadWrite() {
        }
    };

    // Overloaded operator for displaying objects derived from ReadWrite
    std::ostream& operator<<(std::ostream& os, const ReadWrite& c);

    // Overloaded operator for reading objects derived from ReadWrite
    std::istream& operator>>(std::istream& is, ReadWrite& c);
}

#endif // !SDDS_READWRITE_H_
