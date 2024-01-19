#ifndef SDDS_LABELMAKER_H_ // Include guard to prevent multiple inclusions of this header
#define SDDS_LABELMAKER_H_

namespace sdds {
    // The LabelMaker class is designed to create and manage a collection of labels.
    class LabelMaker {
        int noOFLabels; // Holds the number of labels that the LabelMaker will manage
        char** labelsArray; // A dynamic array of pointers to dynamically allocated strings

    public:
        // Constructor: Accepts an integer to set the number of labels and initializes the labelsArray.
        LabelMaker(int);

        // Destructor: Responsible for deallocating the dynamic memory allocated for the labelsArray.
        ~LabelMaker();

        // readLabels: Reads the contents for each label from user input.
        void readLabels();

        // printLabels: Prints all the labels stored in the labelsArray.
        void printLabels();
    };
}

#endif // !SDDS_LABELMAKER_H_
