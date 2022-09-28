// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include <iostream>
#include <algorithm>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (int i = 0; i < desc.size(); i++)
		{
			if (desc[i].code == price[i].code)
			{
				Product* p = new Product(desc[i].desc, price[i].price);
				p->validate();
				priceList += p;
			}
		}

		return priceList;
	}
}