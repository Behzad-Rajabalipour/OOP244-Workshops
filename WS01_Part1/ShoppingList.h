#ifndef SDDS_SHOPPINGLIST_H_
#define	SDDS_SHOPPINGLIST_H_
#include "ShoppingRec.h"
#include "Utils.h"
#include "File.h"

namespace sdds {

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}
#endif 