//Workshop 04 - Containers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 10, 2021
//ConfirmationSender.cpp

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#include <iostream>
#include "ConfirmationSender.h"

using namespace sdds;

ConfirmationSender::ConfirmationSender()
{
	resPointers = nullptr;
	numOfResPointers = 0u;
}

ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
{
	*this = src;
}

ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& obj)
{
	if (this != &obj)
	{
		resPointers = new const Reservation*[obj.numOfResPointers];
		numOfResPointers = obj.numOfResPointers;

		for (size_t x = 0; x < numOfResPointers; x++)
		{
			resPointers[x] = obj.resPointers[x];
		}
	}

	return *this;
}

ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)noexcept
{
	if (this != &src)
		*this = std::move(src);
}

ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)noexcept
{
	if (this != &src) {
		delete[] resPointers;
		resPointers = src.resPointers;
		src.resPointers = nullptr;

		numOfResPointers = src.numOfResPointers;
		src.numOfResPointers = 0u;
	}

	return *this;
}

ConfirmationSender::~ConfirmationSender()
{
	delete[] resPointers;
	resPointers = nullptr;
}

ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
{
	bool alreadyIn = false;

	for (size_t i = 0; i < numOfResPointers; i++)
	{
		if (resPointers[i] == &res)
		{
			alreadyIn = true;
		}
	}

	if (!alreadyIn)
	{
		const Reservation** outdated = new const Reservation*[numOfResPointers];
		for (size_t i = 0; i < numOfResPointers; i++)
		{
			outdated[i] = resPointers[i];
		}

		delete[] resPointers;
		resPointers = nullptr;

		resPointers = new const Reservation*[numOfResPointers + 1];
		for (size_t i = 0; i < numOfResPointers; i++)
		{
			resPointers[i] = outdated[i];
		}

		resPointers[numOfResPointers] = &res;

		numOfResPointers++;

		delete[] outdated;
		outdated = nullptr;
	}

	return *this;
}

ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
{
	bool alreadyIn = false;

	for (size_t i = 0; i < numOfResPointers; i++)
	{
		if (resPointers[i] == &res)
		{
			resPointers[i] = nullptr;
			alreadyIn = true;
		}
	}

	if (alreadyIn)
	{
		const Reservation** outdated = new const Reservation*[numOfResPointers];
		for (size_t i = 0; i < numOfResPointers; i++)
		{
			outdated[i] = resPointers[i];
		}

		delete[] resPointers;
		resPointers = nullptr;

		resPointers = new const Reservation*[numOfResPointers - 1];
		for (size_t i = 0, x = 0; i < numOfResPointers; i++, x++)
		{
			if (outdated[i] != nullptr)
			{
				resPointers[x] = outdated[i];
			}
			else
				x--;
		}

		numOfResPointers--;

		delete[] outdated;
		outdated = nullptr;
	}

	return *this;
}

std::ostream& sdds::operator<<(std::ostream& os, const ConfirmationSender& obj)
{
	os << "--------------------------" << std::endl;
	os << "Confirmations to Send" << std::endl;
	os << "--------------------------" << std::endl;

	if (obj.numOfResPointers > 0)
	{
		for (size_t i = 0; i < obj.numOfResPointers; i++)
		{
			os << *obj.resPointers[i];
		}
	}
	else
	{
		os << "There are no confirmations to send!" << std::endl;
	}

	os << "--------------------------" << std::endl;

	return os;
}