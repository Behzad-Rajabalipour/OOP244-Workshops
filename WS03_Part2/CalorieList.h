#ifndef SDDS_CALORIELIST_H_
#define	SDDS_CALORIELIST_H_
#include "Food.h"

namespace sdds {
	class CalorieList {
	private:
		int size;
		Food* m_foodItems;
		int m_addedItems = 0;


	public:
		void init(int);
		bool add(const char*, int, int);
		void deallocate();
		bool isValid();
		void display();						// when method is const then we can no change anything in this method.
	};

}

#endif // !1
