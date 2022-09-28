//Workshop 06 - STLContainers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 07, 2021
//Autoshop.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef AUTOSHOP_H
#define AUTOSHOP_H

#include <vector>
#include "Vehicle.h"

namespace sdds {

	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto m_vehicle : m_vehicles)
			{
				if (test(m_vehicle)) vehicles.push_back(m_vehicle);				
			}
		}
	};

}

#endif