#ifndef SDDS_SHOPPINGREC_H_
#define	SDDS_SHOPPINGREC_H_
#include "Utils.h"

namespace sdds {
	const int MAX_TITLE_LENGTH = 50;			// constant value. because they used in header file we should put them here, otherwise if they used in cpp we should put them in cpp file
	struct ShoppingRec
	{
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};
	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec*);
	void toggleBoughtFlag(ShoppingRec*);
	bool isShoppingRecEmpty(const ShoppingRec*);

}
#endif 