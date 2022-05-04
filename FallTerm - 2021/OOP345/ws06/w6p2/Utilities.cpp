//Workshop 06 - STLContainers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 07, 2021
//Utilities.cpp

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

using namespace sdds;
Vehicle* sdds::createInstance(std::istream& in)
{
	std::string record = "";
	char carType = '\0';

	getline(in, record, '\n');

	size_t typeIndex = record.find_first_not_of(' ');

	if (typeIndex != std::string::npos) carType = record[typeIndex];

	std::stringstream ss(record);

	if (carType != '\0')
	{
		switch (carType) {
		case 'C':
		case 'c':
			return new Car(ss);
			break;
		case 'R':
		case 'r':
			return new Racecar(ss);
			break;
		default:
			throw carType;
			break;
		}

	}

	return nullptr;
}