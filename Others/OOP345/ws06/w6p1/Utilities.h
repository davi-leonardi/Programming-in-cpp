#ifndef UTILITIES_H
#define	UTILITIES_H

#include <iostream>
#include <sstream>
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		std::string record = "";
		char type = '\0';

		getline(in, record, '\n');

		size_t typeIndex = record.find_first_not_of(' ');

		if (typeIndex != std::string::npos) type = record[typeIndex];

		std::stringstream ss(record);

		switch(type){
		case 'C':
		case 'c':
			return new Car(ss);
			break;
		default:
			return nullptr;
		}

	}
}

#endif
