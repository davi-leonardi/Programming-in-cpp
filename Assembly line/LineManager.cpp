// Name: Davi Leonardi Mathey
// Seneca Student ID: 154979199
// Seneca email: dleonardi-mathey@myseneca.ca
// Date of completion: Dec 2, 2021

// I confirm that I am the only author of this file and the content was created entirely by me.

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace sdds;

LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
{
	std::string record;
	Utilities utilities;
	m_firstStation = nullptr;
	m_cntCustomerOrder = 0u;

	try {
		std::ifstream in(file);

		while (std::getline(in, record))
		{
			std::string firstField, secondField;
			bool more = true;
			size_t nextPos = 0u;

			firstField = utilities.extractToken(record, nextPos, more);
			secondField = utilities.extractToken(record, nextPos, more);

			auto lambda = [&](Workstation* wst) {
				if (wst->getItemName() == firstField)
				{
					std::for_each(stations.begin(), stations.end(), [&](Workstation* lastSt) {
						if (lastSt->getItemName() == secondField)
						{
							wst->setNextStation(lastSt);
						}
						});

					activeLine.push_back(wst);
				}
			};

			std::for_each(stations.begin(), stations.end(), lambda);
			m_firstStation = activeLine.front();
			m_cntCustomerOrder = pending.size();
		}
	}
	catch (...) {
		throw std::string("Error");
	}
}

void LineManager::linkStations()
{
	std::vector<Workstation*> reordered;
	reordered.push_back(m_firstStation);
	size_t y = 0;

	std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* wst) {

		for (size_t x = 0; x < activeLine.size(); x++, y++)
		{
			if (reordered[y]->getNextStation() == activeLine[x])
			{
				reordered.push_back(activeLine[x]);
			}
			else
				y--;
		}
	});
	
	activeLine = reordered;
	reordered.clear();
}

bool LineManager::run(std::ostream& os)
{
	static size_t counter = 1;
	bool rtn = false;

	os << "Line Manager Iteration: " << counter << std::endl;

	counter++;

	if (!pending.empty())
	{
		*m_firstStation += std::move(pending.front());
		pending.pop_front();
	}

	for (size_t i = 0; i < activeLine.size(); i++)
	{
		activeLine[i]->fill(os);
	}

	for (size_t i = 0; i < activeLine.size(); i++)
	{
		activeLine[i]->attemptToMoveOrder();
	}

	if (completed.size() + incomplete.size() == m_cntCustomerOrder) rtn = true;

	return rtn;
}

void LineManager::display(std::ostream& os) const
{
	for (size_t i = 0; i < activeLine.size(); i++)
	{
		activeLine[i]->display(os);
	}
}