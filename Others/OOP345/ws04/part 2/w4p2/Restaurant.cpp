//Workshop 04 - Containers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 10, 2021
//Restaurant.cpp

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"

using namespace sdds;

Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
{
	delete[] reservation;
	reservation = nullptr;

	reservation = new Reservation[cnt];
	numOfReservations = cnt;

	for (size_t x = 0; x < cnt; x++)
	{
		reservation[x] = *reservations[x];
	}

	numOfReservations = cnt;	
}

Restaurant::Restaurant(const Restaurant& obj)
{
	*this = obj;
}

Restaurant& Restaurant::operator=(const Restaurant& obj)
{
	if (this != &obj)
	{
		delete[] reservation;
		reservation = nullptr;

		reservation = new Reservation[obj.numOfReservations];
		numOfReservations = obj.numOfReservations;

		for (size_t x = 0; x < numOfReservations; x++)
		{
			reservation[x] = obj.reservation[x];
		}
	}

	return *this;
}

Restaurant::Restaurant(Restaurant&& src)noexcept
{
	if (this != &src)
		*this = std::move(src);
}

Restaurant& Restaurant::operator=(Restaurant&& src)noexcept
{
	if (this != &src) {
		delete[] reservation;
		reservation = src.reservation;
		src.reservation = nullptr;

		numOfReservations = src.numOfReservations;
		src.numOfReservations = 0u;
	}

	return *this;
}

size_t Restaurant::size() const
{
	return numOfReservations;
}

std::ostream& sdds::operator<<(std::ostream& os, const sdds::Restaurant& obj)
{
	static size_t counter = 1;

	os << "--------------------------" << std::endl;
	os << "Fancy Restaurant (" << counter << ")" << std::endl;
	os << "--------------------------" << std::endl;

	if (obj.numOfReservations > 0)
	{
		for (size_t i = 0; i < obj.numOfReservations; i++)
		{
			os << obj.reservation[i];
		}
	}
	else
	{
		os << "This restaurant is empty!" << std::endl;
	}

	os << "--------------------------" << std::endl;

	counter++;

	return os;
}

Restaurant::~Restaurant()
{
	delete[] reservation;
	reservation = nullptr;
}