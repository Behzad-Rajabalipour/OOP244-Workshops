#ifndef SDDS_LABEL_H_ // Include guard to prevent multiple inclusions
#define SDDS_LABEL_H_

namespace sdds {
    class Label {
        char* frame = new char[71]; // Dynamic allocation for frame
        char* content = new char[71]; // Dynamic allocation for content

    public:
        // Default constructor: Initializes a Label with empty frame and content
        Label();

        // Constructor with frame argument: Initializes a Label with provided frame and empty content
        Label(const char*);

        // Constructor with frame and content arguments: Initializes a Label with provided frame and content
        Label(const char*, const char*);

        // Destructor: Responsible for deallocating dynamic memory
        ~Label();

        // Method for reading label content from user input
        void readLabel();

        // Method for printing the label with appropriate formatting
        std::ostream& printLabel() const;
    };
}

#endif // SDDS_LABEL_H_ ends the ifndef condition
