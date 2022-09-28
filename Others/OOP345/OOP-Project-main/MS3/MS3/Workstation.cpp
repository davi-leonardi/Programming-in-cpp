// Name: Davi Leonardi Mathey
// Seneca Student ID: 154979199
// Seneca email: dleonardi-mathey@myseneca.ca
// Date of completion: Dec 2, 2021

// I confirm that I am the only author of this file and the content was created entirely by me.

#include <iostream>
#include "Workstation.h"

namespace sdds {

	std::deque<CustomerOrder> pending = {};
	std::deque<CustomerOrder> completed = {};
	std::deque<CustomerOrder> incomplete = {};

	Workstation::Workstation(const std::string& str) : Station(str)
	{
		m_pNextStation = nullptr;
	}

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty()) m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool rtn = false;

		if (!m_orders.empty())
		{
			if(m_orders.front().isItemFilled(getItemName()))
			{
				if (m_pNextStation)
					*m_pNextStation += std::move(m_orders.front());
				else
				{
					if (m_orders.front().isFilled())
						completed.push_back(std::move(m_orders.front()));
					else
						incomplete.push_back(std::move(m_orders.front()));
				}

				m_orders.pop_front();
			}
			else if(getQuantity() <= 0)
			{
				if (m_pNextStation)
					*m_pNextStation += std::move(m_orders.front());
				else
					incomplete.push_back(m_orders.front());

				m_orders.pop_front();
			}

			rtn = true;
		}

		return rtn;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{

		if (m_pNextStation)
			os << getItemName() << " --> " << m_pNextStation->getItemName();
		else
			os << getItemName() << " --> End of Line";

		os << std::endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));

		return *this;
	}

}