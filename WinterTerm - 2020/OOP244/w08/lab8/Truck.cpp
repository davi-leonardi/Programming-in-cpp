//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 17, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "MotorVehicle.h"
#include "Truck.h"

namespace sdds {

	Truck::Truck(const char* plate, int year, double capacity, const char* address) : MotorVehicle(plate, year)
	{
		m_cargo = 0.00;
		m_capacity = capacity;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		bool checker = false;

		if (m_cargo < m_capacity)
		{
			if (m_cargo + cargo >= m_capacity)
			{
				m_cargo = m_capacity;
			}
			else
			{
				m_cargo += cargo;
			}

			checker = true;
		}

		return checker;
	}

	bool Truck::unloadCargo()
	{
		bool checker = m_cargo > 0;

		if (checker)
		{
			m_cargo = 0;
		}

		return checker;

	}

	std::ostream& Truck::write(std::ostream& os)
	{
		return os << "| " << getYear() << " | " << getPlate() << " | " << getAddress() << " | " << m_cargo << "/" << m_capacity;
	}

	std::istream& Truck::read(std::istream& in)
	{
		std::cout << "Built year: ";
		in >> getYear();
		std::cout << "License plate: ";
		in >> getPlate();
		std::cout << "Current location: ";
		in >> getAddress();
		std::cout << "Capacity: ";
		in >> m_capacity;
		std::cout << "Cargo: ";
		in >> m_cargo;

		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, Truck& obj)
	{
		return obj.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Truck& obj)
	{
		return obj.read(istr);
	}

}