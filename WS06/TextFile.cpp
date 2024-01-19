#include <iostream>                                 // Include the iostream library, which is a combination of ostream and istream for cout and cin.
#include <fstream>                                  // Include the fstream library, which is a combination of ofstream and ifstream for reading and writing files.
#include <string>                                   // Include the string library.
#include "iomanip"                                  // Include the iomanip library for formatting.
#include "TextFile.h"                               // Include the header file TextFile.h.
#include "cstring.h"                               // Include the header file cstring.h for string manipulation functions.
using namespace std;                                // Allow the use of standard namespace.

namespace sdds {
    // =================================================
    // Line
    Line::operator const char* () const {            // Define a type conversion operator that allows Line objects to be treated as const char* strings. Example usage: Line ob1("behzad"); cout << "hi" + ob1 + " how are you";
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {   // Define the assignment operator for Line objects. It assigns a char* to a Line object. Example usage: Line obj1("behzad"); obj1 = "newvalue";
        delete[] m_value;                             // Always delete before allocating memory for a new dynamic pointer.
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        if (m_value != nullptr) {
            delete[] m_value;
            m_value = nullptr;
        }
    }

    void TextFile::setEmpty() {
        if (m_textLines != nullptr) {
            delete[] m_textLines;               // Release memory occupied by the previous text lines.
            m_textLines = nullptr;
        }

        if (m_filename != nullptr) {
            delete[] m_filename;               // Release memory occupied by the previous filename.
            m_filename = nullptr;
        }

        m_noOfLines = 0;                      // Initialize the number of lines to 0.
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;                 // Release memory occupied by the previous filename.
        if (isCopy) {
            m_filename = new char[strLen(m_preText) + strLen(fname) + 1];  // Allocate memory for the new filename.
            strCpy(m_filename, m_preText);         // Concatenate m_preText at the beginning of the char array.
            strCat(m_filename, fname);            // Concatenate the provided filename.
        }
        else {
            m_filename = new char[strLen(fname) + 1];  // Allocate memory for the new filename.
            strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        m_noOfLines = 0;                      // Initialize the number of lines to 0.

        // This is another way to count the number of lines in the file.
        ifstream fin(m_filename);
        char ch;
        if (fin.is_open()) {                                             // Check if the file is open.
            while (fin.get(ch)) {
                m_noOfLines += (ch == '\n');  // Count lines based on newline character.
            }
            m_noOfLines++;                  // Increment by 1 to include the last line.
        }
        else {
            delete[] m_filename;             // Release memory occupied by the filename.
            m_filename = nullptr;
        }
    }

    void TextFile::loadText() {
        if (m_filename != nullptr) {
            if (m_textLines != nullptr) {
                delete[] m_textLines;               // Release memory occupied by the previous text lines.
                m_textLines = nullptr;
            }

            ifstream fin(m_filename);               // Open the file for reading.
            string line;                             // Use a string to store each line because we don't know its length.

            int i = 0;
            delete m_textLines;                                      // Always delete before allocating memory for a new dynamic pointer.
            m_textLines = new Line[m_noOfLines];          // Allocate memory for an array of Line objects.
            if (fin.is_open()) {
                while (getline(fin, line)) {                        // Read lines from the file.
                    m_textLines[i] = line.c_str();                 // Convert string to char* and assign to Line object.
                    i++;
                }
            }
            m_noOfLines = i;                            // Update the number of lines.
        }
    }

    void TextFile::saveAs(const char* fileName)const {
        ofstream fout(fileName);                                 // Open the file for writing.
        for (unsigned i = 0; i < m_noOfLines; i++) {             // Loop through lines and write them to the file.
            fout << m_textLines[i] << endl;                     // Add endl at the end of each line.
        }
    }

    TextFile::TextFile(unsigned pageSize) {
        setEmpty();                          // Initialize the object's members.
        m_pageSize = pageSize;              // Set the page size.
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        m_pageSize = pageSize;              // Set the page size.
        setEmpty();                          // Initialize the object's members.

        if (filename != nullptr && filename[0] != '\0') {                 // Check if the filename is valid and not empty.
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& ob1) {                            // Copy Constructor.
        setEmpty();                          // Initialize the object's members.
        this->m_pageSize = ob1.m_pageSize;   // Copy the page size from ob1.
        if (this != &ob1) {                 // Check if the objects are not the same.
            if (ob1.m_textLines && ob1.m_noOfLines > 0) {
                setFilename(ob1.m_filename);
                setNoOfLines();
                loadText();
                setFilename(ob1.m_filename, true);  // Create a copy of the filename with a prefix.
                saveAs(m_filename);                 // Save the file with the new name.
            }
        }
    }

    TextFile& TextFile::operator=(const TextFile& ob1) {              // Copy Assignment. 
        if (this != &ob1) {                 // Check if the objects are not the same.
            if (m_textLines != nullptr) {
                delete[] m_textLines;        // Release memory occupied by the previous text lines.
                m_textLines = nullptr;
            }

            delete[] m_textLines;            // Always delete before allocating memory for a new dynamic pointer.
            if (ob1.m_textLines && ob1.m_noOfLines > 0) {
                this->m_noOfLines = ob1.m_noOfLines;     // Copy the number of lines.
                m_textLines = new Line[m_noOfLines];     // Allocate memory for an array of Line objects.
            }

            for (unsigned i = 0; i < m_noOfLines; i++)       // Copy the values from ob1 to this object.
                m_textLines[i] = ob1.m_textLines[i].m_value;

            saveAs(m_filename);                 // Save the file with the same name.
        }
        return *this;
    }

    TextFile::~TextFile() {
        setEmpty();                          // Clean up and release memory.
    }

    unsigned TextFile::lines()const {
        return m_noOfLines;                  // Return the number of lines.
    }

    ostream& TextFile::view(ostream& ostr) const {
        if (m_filename != nullptr && m_filename[0] != '\0') {
            ostr << m_filename << endl
                << setw(strLen(m_filename)) << left << setfill('=') << "" << endl;
            unsigned i = 0;
            for (; i < m_noOfLines && i < m_pageSize; i++) {
                ostr << m_textLines[i] << endl;  // Output lines up to the page size.
            }

            while (i < m_noOfLines) {
                ostr << "Hit ENTER to continue...";
                cin.get();                                           // Read a single character (e.g., Enter).
                for (unsigned j = 0; i < m_noOfLines && j < m_pageSize; j++, i++) {
                    ostr << m_textLines[i] << endl;  // Output more lines after pressing Enter.
                }
            }
        }

        return ostr;
    }

    istream& TextFile::getFile(istream& istr) {
        string filename;                // Use a string to store the filename because we don't know its length.
        istr >> filename;
        delete[] m_filename;
        m_filename = new char[strLen(filename.c_str()) + 1];  // Allocate memory for the new filename.
        strCpy(m_filename, filename.c_str());
        istr.ignore(1000, '\n');              // Ignore the newline character after reading the filename.
        setNoOfLines();
        loadText();
        return istr;
    }

    const char* TextFile::operator[](unsigned index) const {                     // Access lines using the [] operator.
        if (m_filename != nullptr && m_filename[0] != '\0') {
            if (index >= m_noOfLines) {
                index -= m_noOfLines;                                    // Loop back to the beginning if the index is larger than the number of lines.
            }
        }
        return m_textLines[index];
    }

    TextFile::operator bool() const {                                           // Convert to bool.
        if (m_textLines != nullptr) return true;
        else return false;
    }

    TextFile::operator int() const {                                            // Convert to int.
        return m_noOfLines;
    }

    const char* TextFile::name() const {
        return m_filename;
    }

    ostream& operator<<(ostream& ostr, const TextFile& text) {                       // Overloaded << operator for output.
        return text.view(ostr);
    }

    istream& operator>>(istream& istr, TextFile& text) {                             // Overloaded >> operator for input.
        return text.getFile(istr);
    }
}
