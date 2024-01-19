#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
   const char m_preText[3] = "C_";                   // global variable
   /*
       char* p = nullptr;       // when we use =nullptr for pointer then we can use if(p){}; 
   */

   // each class Line has only one line of text
   class Line {                             // fully private and only accessible by the TextFile class. #ref1
      char* m_value{ nullptr };
      operator const char* ()const;       
      Line() {};                             // even constructor is private. because it does nothing, we don't write it in .cpp file, just don't forget {}
      Line& operator=(const char*);
      ~Line();
      friend class TextFile;                // #ref1. only class TextFile() has access to Line private variables and methods

   };

   class TextFile {
      Line* m_textLines = nullptr;                // pointer array class of Lines. we have to start with nullptr otherwise we got error = uninitialised value(s)
      char* m_filename = nullptr;                 // just in class => (char* m_filename;) = (char* m_filename = nullptr;)
      unsigned m_noOfLines;             // unassigned means just positive int
      unsigned m_pageSize;
      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();
   public:
      TextFile(unsigned pageSize = 15);                             // if doesn't give pageSize then = 15. we only use =15 in .h file
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile&);                            // copy constructor. 
      TextFile& operator=(const TextFile&);                 // copy Assignment
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      operator int() const;                                     
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;                  // input goes inside [] => cout << ob1[3];
   };
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__
