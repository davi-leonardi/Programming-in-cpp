//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#pragma once

#ifndef NAMESPACE_SHOPPINGLIST_H // replace with relevant names
#define NAMESPACE_SHOPPINGLIST_H
#include "ShoppingRec.h"

namespace sdds {

	const int MAX_NO_OF_RECS = 15;

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}
#endif