//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "cstring.h"
#include "Bill.h"
#include "Item.h"
using namespace std;
namespace sdds {

	void Bill::init(const char* title, int noOfItems) 
	{
		if (title == '\0' || noOfItems <= 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strCpy(m_title, title);

			m_items = nullptr;
			m_items = new Item[m_noOfItems];
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		if (m_itemsAdded < m_noOfItems)
		{
			
			m_items[m_itemsAdded].set(item_name, price, taxed);

			m_itemsAdded++;
			return true;
		}
		else
		{
			return false;
		}
	}

	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const
	{
		if (m_title[0] != '\0' && m_items != nullptr)
		{
			for (int i = 0; i < m_noOfItems; i++)
			{
				if (m_items[i].isValid() == false)
				{
					return false;
				}
			}
		}

		return true;
	}

	double Bill::totalTax()const
	{
		double tax = 0.00;

		for (int i = 0; i < m_noOfItems; i++)
		{			
			tax += m_items[i].tax();
		}

		return tax;
	}

	double Bill::totalPrice()const
	{
		double price = 0.00;

		for (int i = 0; i < m_noOfItems; i++)
		{
			price += m_items[i].price();
		}

		return price;
	}

	void Bill::Title()const
	{
		cout << "+--------------------------------------+" << endl;

		if (isValid())
		{
			cout << "| ";
			cout.width(36);
			cout << left << m_title;
			cout << " |" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;

	}

	void Bill::footer()const
	{
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid())
		{
			double tt = totalTax();
			double tp = totalPrice();
			double tat = tt + tp;

			cout << "|                Total Tax: ";
			cout.width(10);
			cout << fixed;
			cout.precision(2);
			cout.setf(ios::right);
			cout << tt << " |" << endl;

			cout << "|              Total Price: ";
			cout.width(10);
			cout << fixed;
			cout.precision(2);
			cout << tp << " |" << endl;

			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << fixed;
			cout.precision(2);			
			cout << tat << " |" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+--------------------------------------+" << endl;
	}

	void Bill::display()const
	{
		int x = 0;
		x = m_itemsAdded;

		while (x < m_noOfItems)
		{			
			m_items[x].setEmpty();
			x++;
		}
		
		Title();
		
		int i;

		for (i = 0; i < m_noOfItems; i++)
		{	
			m_items[i].display();
		}

		footer();
	}


	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}

}