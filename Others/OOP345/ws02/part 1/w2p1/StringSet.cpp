#include <string>
#include <fstream>
#include "StringSet.h"

using namespace sdds;

StringSet::StringSet()
{
	records = nullptr;
	numStr = 0u;
}

StringSet::StringSet(const char* arr)
{
		numStr = 0u;
		std::ifstream file(arr);
		std::string str;

		if (file.good())
		{
			while (!file.eof())
			{
				getline(file, str, ' ');
				numStr++;
			}
		}
		file.close();
		file.open(arr);
		records = new std::string[numStr];
		if (file.is_open())
		{
			for (unsigned int i = 0; i < numStr; i++)
				std::getline(file, records[i], ' ');
		}

		file.close();
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