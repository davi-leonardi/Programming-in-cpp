//Workshop 06 - STLContainers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 07, 2021
//Autoshop.cpp

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#include <list>
#include "Autoshop.h"
using namespace sdds;

Autoshop& Autoshop::operator +=(Vehicle* theVehicle)
{
	m_vehicles.push_back(theVehicle);

	return *this;
}

void Autoshop::display(std::ostream& out) const
{
	out << "--------------------------------" << std::endl;
	out << "| Cars in the autoshop!        |" << std::endl;
	out << "--------------------------------" << std::endl;

	for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
	{
		(*i)->display(out);
		out << std::endl;
	}

	out << "--------------------------------" << std::endl;
}

Autoshop::~Autoshop()
{
	for (size_t i = 0; i < m_vehicles.size(); i++)
	{
		delete (m_vehicles[i]);
	}

	m_vehicles.clear();
}
