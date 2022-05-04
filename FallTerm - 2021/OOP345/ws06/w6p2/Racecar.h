//Workshop 06 - STLContainers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 07, 2021
//Racecar.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef RACECAR_H
#define RACECAR_H

#include "Car.h"

namespace sdds {

	class Racecar : public Car {
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};

}

#endif