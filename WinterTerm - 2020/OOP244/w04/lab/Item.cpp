//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "cstring.h"
#include "Item.h"
#include "Bill.h"
using namespace std;
namespace sdds {

#define TAX 0.13

	void Item::set(const char* name, double price, bool taxed)
	{
		if (name == '\0' || price < 0)
		{
			setEmpty();
		}
		else
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	void Item::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.fill('.');
			cout.width(20);
			cout.setf(ios::left);
			cout << m_itemName;
			cout << " | ";

			cout.fill(' ');
			cout.width(7);
			cout << fixed;
			cout.precision(2);
			cout.unsetf(ios::left);
			cout << m_price;
			cout << " | ";

			if (m_taxed)
			{
				cout << "Yes |" << endl;
			}
			else
			{
				cout << "No  |" << endl;
			}
			
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}

	bool Item::isValid()const
	{
		if (m_itemName[0] != '\0' && m_price != 0.00)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Item::setEmpty()
	{
		m_itemName[0] = '\0';
		m_price = 0.00;
	}

	void Item::setName(const char* name)
	{
		m_itemName[20] = '\0';
		if (strLen(name) > 20)
		{			
			strnCpy(m_itemName, name, 20);			
		}
		else
		{		
			strCpy(m_itemName, name);		
		}
	}

	double Item::tax()const
	{
		double tax = 0.00;

		if (m_taxed == true)
		{			
			tax = m_price * TAX;			
		}

		return tax;
	}

	double Item::price()const
	{
		return m_price;
	}

}