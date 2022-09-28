//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 17, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MotorVehicle.h"
#include "cstring.h"

namespace sdds {

	MotorVehicle::MotorVehicle(const char* plate, int year)
	{
		m_year = year;
		strCpy(m_plate, plate);
		strCpy(m_address, "Factory");
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(m_address, address) != 0)
		{

			std::cout << "|"; 
			std::cout.width(8);
			std::cout << std::right << m_plate << "| |";
			std::cout.width(20);
			std::cout << std::right << m_address << " ---> ";
			std::cout.width(20);
			std::cout << std::left << address << "|" << std::endl;

			m_address[0] = '\0';
			strCpy(m_address, address);

		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os)const
	{
		return os << "| " << m_year << " | " << m_plate << " | " << m_address;
	}

	std::istream& MotorVehicle::read(std::istream& in)
	{
		std::cout << "Built year: ";

		in >> m_year;

		std::cout << "License plate: ";
		in >> m_plate;

		std::cout << "Current location: ";
		in >> m_address;

		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& obj)
	{
		return obj.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, MotorVehicle& obj)
	{
		return obj.read(istr);
	}

	char* MotorVehicle::getAddress()
	{
		return m_address;
	}

	char* MotorVehicle::getPlate()
	{
		return m_plate;
	}

	int& MotorVehicle::getYear()
	{
		return m_year;
	}

}