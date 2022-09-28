#pragma once
//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 17, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_

#include "MotorVehicle.h"

namespace sdds {

	class Truck : public MotorVehicle {
		double m_capacity;
		double m_cargo;
	public:
		Truck(const char* m_plate, int year, double capacity, const char* m_address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& ostr, Truck& obj);
	std::istream& operator>>(std::istream& istr, Truck& obj);

}

#endif // SDDS_TRUCK_H_