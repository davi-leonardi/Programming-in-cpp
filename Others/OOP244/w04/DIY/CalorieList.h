//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#include "Food.h"

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_

using namespace std;
namespace sdds {
	class CalorieList
	{
		Food* food;
		int noOfItems;
		int noOfItemsAdd;
		void footer()const;
		void title()const;
		bool isValid()const;
		int totalCal()const;
	public:
		void init(int size);
		bool add(const char* item_name, int calories, int when);
		void display()const;				
		void deallocate();
	};
}
#endif