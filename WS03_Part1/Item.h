#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_

namespace sdds {
   class Item {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);                               // because input is pointer so it is call by referenec
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);         // setter
      void display()const;
      bool isValid()const;
      double price()const;                                          // getter
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
