#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
#include "cstring.h"
#include "iomanip"

namespace sdds {
	class Food {
	private:
		char m_item_name[30];
		int m_calories;
		int m_when;
	public:
		bool isValid();
		void set(const char*, int, int);
		void display();
		int calories_getter();
		void setEmpty();

	};
}


#endif // !SDDS_FOOD_H_

