#include <iostream>
#include <iomanip>
#include "Car.h"

using namespace sdds;

Car::Car(std::istream& in)
{
	std::string str = "", trash = "", condition = "";

	getline(in, str, '\n');

	trash = trim(str.substr(0, str.find(',')));

	str = str.erase(0, str.find(',') + 1);
	m_maker = trim(str.substr(0, str.find(',')));

	str = str.erase(0, str.find(',') + 1);
	condition = trim(str.substr(0, str.find(',')));

	str = str.erase(0, str.find(',') + 1);
	m_topSpeed = stod(trim(str.substr(0, str.find('\n'))));

	if (condition == "n") m_condition = Condition::n;
	else if (condition == "b") m_condition = Condition::b;
	else m_condition = Condition::u;
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
	os << std::setw(6) << condition() << " | ";
	os << std::setw(6) << std::fixed  << std::setprecision(2) << m_topSpeed << " |" << std::endl;
}

std::string Car::trim(const std::string& str)
{
	std::string rtn = "";

	size_t ltrimIndex = str.find_first_not_of(' ');

	if (ltrimIndex != std::string::npos)
	{
		size_t rtrimIndex = (str.find_last_not_of(' ') - ltrimIndex);
		rtn = str.substr(ltrimIndex, rtrimIndex + 1);
	}

	return rtn;
}