//Workshop 06 - STLContainers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 07, 2021
//w6_p2.cpp

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "Autoshop.h"
#include "Autoshop.h"
#include "Utilities.h"
#include "Utilities.h"

void loadData(const char* filename, sdds::Autoshop& as)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{
		sdds::Vehicle* aVehicle = nullptr;

		try 
		{
			aVehicle = sdds::createInstance(file);
		}
		catch (const char type)
		{
			std::cout << "Unrecognized record type: [" << type << ']' << std::endl;
		}
		catch (...)
		{
			std::cout << "Invalid record!" << std::endl;
		}


		if (aVehicle)
			as += aVehicle;
	}
}

// ws dataClean.txt dataMessy.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Autoshop as;
	loadData(argv[1], as);
	as.display(std::cout);
	std::cout << "\n";
	loadData(argv[2], as);
	as.display(std::cout);

	std::cout << std::endl;
	std::list<const sdds::Vehicle*> vehicles;
	{
		auto fastVehicles = [&](const sdds::Vehicle* vehicle) { return vehicle->topSpeed() > 300 ? true : false; };
		as.select(fastVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "|       Fast Vehicles          |\n";
		std::cout << "--------------------------------\n";
		for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
		{
			(*it)->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	vehicles.clear();
	std::cout << std::endl;
	{
		auto brokenVehicles = [&](const sdds::Vehicle* vehicle) { return vehicle->condition() == "broken" ? true : false; };
		as.select(brokenVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "| Vehicles in need of repair   |\n";
		std::cout << "--------------------------------\n";
		for (const auto vehicle : vehicles)
		{
			vehicle->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}
	return 0;
}
