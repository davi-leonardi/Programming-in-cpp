// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 19, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t x = 0; x < price.size(); x++)
			{
				if (desc[i].code == price[x].code)
				{
					Product* p = new Product(desc[i].desc, price[x].price);
					p->validate();
					priceList += p;
					delete p;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t x = 0; x < price.size(); x++)
			{
				if (desc[i].code == price[x].code)
				{
					std::unique_ptr<Product> po(new Product(desc[i].desc, price[x].price));
					po->validate();
					priceList += po;
				}
			}
		}

		return priceList;
	}
}