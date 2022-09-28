//Workshop 06 - STLContainers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 07, 2021
//Car.cpp

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Car.h"

using namespace sdds;

Car::Car(std::istream& in)
{
	std::string str = "", condition = "", speed = "";
	bool digit = true;

	getline(in, str, ',');
	m_type = trim(str);
	str.clear();

	getline(in, str, ',');
	m_maker = trim(str);
	str.clear();

	getline(in, str, ',');
	condition = trim(str);
	str.clear();

	if (condition == "") condition = "n";
	else if (condition != "n" && condition != "u" && condition != "b") throw "Invalid record!";

	if (m_type == "r" || m_type == "R")
	{
		getline(in, str, ',');
		speed = trim(str);
		str.clear();
	}
	else
	{
		getline(in, str, '\n');
		speed = trim(str);
		str.clear();
	}

	for (size_t i = 0; i < speed.size(); i++)
	{
		if (!std::isdigit(speed[i])) digit = false;
	}

	if (digit)
	{
		m_topSpeed = stod(speed);
	}
	else 
	{
		throw "Invalid record!";
	}

	if (condition == "n") m_condition = Condition::n;
	else if (condition == "b") m_condition = Condition::b;
	else if (condition == "u") m_condition = Condition::u;
}

std::string Car::condition() const
{
	std::string condition = "";

	switch (m_condition) {
		case Condition::n:
			condition = "new";
			break;
		case Condition::b:
			condition = "broken";
			break;
		case Condition::u:
			condition = "used";
			break;
	}

	return condition;
}

double Car::topSpeed() const
{
	return m_topSpeed;
}

void Car::display(std::ostream& os) const
{
	os << "| " << std::setw(10) << m_maker << " | ";
	os << std::setw(6) << std::left << condition() << " | ";
	os << std::setw(6) << std::right << std::fixed << std::setprecision(2);

	if (m_type == "c" || m_type == "C") os << m_topSpeed << " |";
}

std::string Car::trim(const std::string& str)
{
	std::string rtn = "";

	size_t ltrimIndex = str.find_first_not_of(' ');

	if (ltrimIndex != std::string::npos && str[ltrimIndex] != ',')
	{
		size_t rtrimIndex = (str.find_last_not_of(' ') - ltrimIndex);
		rtn = str.substr(ltrimIndex, rtrimIndex + 1);
	}

	return rtn;
}