// Workshop 2 - Copy and Move Semantics
//StringSet.cpp
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 02, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <string>
#include <fstream>
#include<utility>
#include "StringSet.h"

using namespace sdds;

StringSet::StringSet()
{
	records = nullptr;
	numStr = 0u;
}

StringSet::StringSet(const char* arr)
{

	std::ifstream in(arr);
	records = nullptr;
	numStr = 0u;
	std::string str;

	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, str, ' ');
			numStr++;
		}
	}
		
	in.close();
	in.open(arr);

	records = new std::string[numStr];

	if (in.is_open())
	{
		for (unsigned int i = 0; i < numStr; i++)
		getline(in, records[i], ' ');
	}

	in.close();	
}

size_t StringSet::size()const
{
	return numStr;
}

std::string StringSet::operator[](size_t index)const
{
	std::string copy = "";
	if (index < numStr && index >= 0)
	{
		copy = records[index];
	}

	return copy;
}

StringSet::StringSet(const StringSet& obj)
{
	records = nullptr;
	numStr = 0u;

	if (this != &obj)
	{

		if (obj.records)
		{
			numStr = obj.numStr;
			records = new std::string[numStr];

			for (unsigned int i = 0; i < numStr; i++)
			{
				records[i] = obj.records[i];
			}

		}
	}

}

StringSet& StringSet::operator=(const StringSet& obj)
{
	if (this != &obj)
	{
		numStr = 0u;

		if (obj.records)
		{
			numStr = obj.numStr;
			delete[] records;
			records = nullptr;

			records = new std::string[numStr];

			for (unsigned int i = 0; i < numStr; i++)
			{
				records[i] = obj.records[i];
			}

		}
	}

	return *this;
}

StringSet::~StringSet()
{
	delete[] records;
	records = nullptr;
}

StringSet::StringSet(StringSet&& src)noexcept
{
	if (this != &src)
		*this = std::move(src);
}

StringSet& StringSet::operator=(StringSet&& src)noexcept
{
	if (this != &src) {
		delete[] records; 
		records = src.records;   
		src.records = nullptr; 

		numStr = src.numStr;
		src.numStr = 0u;
	}
	return *this;
}