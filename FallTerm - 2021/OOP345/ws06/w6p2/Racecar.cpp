//Workshop 06 - STLContainers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 07, 2021
//Racecar.cpp

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#include "Racecar.h"

using namespace sdds;

Racecar::Racecar(std::istream& in) : Car(in)
{
	std::string boost = "";
	getline(in, boost, '\n');
	
	m_booster = stod(boost);
}

void Racecar::display(std::ostream& out) const
{
	Car::display(out);
	out << topSpeed() << " |*";
}

double Racecar::topSpeed() const
{
	return Car::topSpeed() * (1 + m_booster);
}
