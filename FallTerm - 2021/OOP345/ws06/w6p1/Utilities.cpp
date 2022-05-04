/*
#include <iostream>
#include <string>
#include "Utilities.h"

using namespace sdds;

Vehicle* createInstance(std::istream& in)
{
	std::string record = "", type = "";

	getline(in, record, '\n');

	type = record.find_first_not_of(' ');

	in.clear();
	in.seekg(std::ios::beg);

	Vehicle* car = nullptr;

	if (type == "c" || type == "C")
	{
		Car aCar(in);
		car = &aCar;
	}

	return car;
}
*/