//Workshop 06 - STLContainers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 07, 2021
//Car.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

namespace sdds {

	enum class Condition {n, u, b};

	class Car : public Vehicle {
		std::string m_type;
		std::string m_maker;
		Condition m_condition;
		double m_topSpeed;
		std::string trim(const std::string& str);
	public:
		Car(std::istream&);
		double topSpeed() const;
		void display(std::ostream&) const;
		std::string condition() const;
	};

}

#endif
