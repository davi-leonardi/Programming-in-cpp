// Name: Davi Leonardi Mathey
// Seneca Student ID: 154979199
// Seneca email: dleonardi-mathey@myseneca.ca
// Date of completion: Nov 24, 2021

// I confirm that I am the only author of this file and the content was created entirely by me.

#include <iostream>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace sdds;

size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder() : m_lstItem(nullptr)
{
	m_name = "";
	m_product = "";
	m_cntItem = 0u;
}

CustomerOrder::CustomerOrder(const std::string& str) : m_lstItem(nullptr)
{
	Utilities utilities;
	size_t nextPos = 0u;
	bool more = true;

	m_name = utilities.extractToken(str, nextPos, more);
	m_product = utilities.extractToken(str, nextPos, more);

	m_cntItem = std::count(str.begin(), str.end(), utilities.getDelimiter()) - 1;

	m_lstItem = new Item*[m_cntItem];

	for (size_t i = 0; i < m_cntItem; i++)
	{
		m_lstItem[i] = new Item(utilities.extractToken(str, nextPos, more));
	}

	if (CustomerOrder::m_widthField < utilities.getFieldWidth()) 
	{
		CustomerOrder::m_widthField = utilities.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder& obj)
{
	throw std::string("Error");
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj)noexcept
{
	if(this != &obj)
	{
		if (m_lstItem != nullptr)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}

			delete[] m_lstItem;
		}
		
		m_lstItem = obj.m_lstItem;
		obj.m_lstItem = nullptr;

		m_name = obj.m_name;
		m_product = obj.m_product;
		m_cntItem = obj.m_cntItem;

		obj.m_name = "";
		obj.m_product = "";
		obj.m_cntItem = 0u;
	}

	return *this;
}

CustomerOrder::CustomerOrder(CustomerOrder&& obj)noexcept : m_lstItem(nullptr)
{
	*this = std::move(obj);
}

CustomerOrder::~CustomerOrder()
{
	for (size_t i = 0; i < m_cntItem; i++)
	{
		delete m_lstItem[i];
	}	
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::isFilled() const
{
	bool allFilled = true;

	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_isFilled == false) allFilled = false;
	}

	return allFilled;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
	bool allFilled = true;

	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == itemName)
		{
			if (m_lstItem[i]->m_isFilled == false) allFilled = false;
		}
	}

	return allFilled;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() > 0)
		{
			m_lstItem[i]->m_itemName = station.getItemName();
			m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
			m_lstItem[i]->m_isFilled = true;
			station.updateQuantity();
			os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
		}
		else if(m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() == 0)
		{
			os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;

	for (size_t i = 0; i < m_cntItem; i++)
	{
		os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ');
		os << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
		if (m_lstItem[i]->m_isFilled == true)
		{
			os << "FILLED";
		}
		else
		{
			os << "TO BE FILLED";
		}

		os << std::endl;
	}		
}
