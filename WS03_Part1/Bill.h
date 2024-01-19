#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"
#include "cstring.h"

namespace sdds {
   class Bill {
      char m_title[37];
      Item* m_items;
      int m_noOfItems;
      int m_itemsAdded;
      double totalTax()const;
      double totalPrice()const;
      void Title()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;
   public:
      void init(const char* title, int noOfItems);                                  // because it's const so we can input sting directly
      bool add(const char* item_name, double price, bool taxed);
      void display()const;                              // when method is const, it means this method doesn't change anything. function can not be const
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
