//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#pragma once
#ifndef NAMESPACE_FILE_H // replace with relevant names
#define NAMESPACE_FILE_H
#include "ShoppingRec.h"

namespace sdds {
	const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif