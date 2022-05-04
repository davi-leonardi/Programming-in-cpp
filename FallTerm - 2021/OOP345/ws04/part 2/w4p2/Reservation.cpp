//Workshop 04 - Containers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 10, 2021
//Reservation.cpp

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Reservation.h"

using namespace sdds;

Reservation::Reservation()
{
	id = "";
	name = "";
	email = "";
	numOfPeople = 0u;
	day = 0;
	hour = 0;
}

Reservation::Reservation(const Reservation& obj)
{
	*this = obj;
}

Reservation& Reservation::operator=(const Reservation& obj)
{
	if (this != &obj)
	{
		id = obj.id;
		name = obj.name;
		email = obj.email;
		numOfPeople = obj.numOfPeople;
		day = obj.day;
		hour = obj.hour;
	}

	return *this;
}

void Reservation::update(int day, int time)
{
	this->day = day;
	this->hour = time;
}

Reservation::Reservation(const std::string& res)
{
	std::string str = res;

	id = trim(str.substr(0, str.find(':')));

	str = str.erase(0, str.find(':') + 1);
	name = trim(str.substr(0, str.find(',')));

	str = str.erase(0, str.find(',') + 1);
	email = trim(str.substr(0, str.find(',')));

	str = str.erase(0, str.find(',') + 1);
	numOfPeople = stoul(trim(str.substr(0, str.find(','))));

	str = str.erase(0, str.find(',') + 1);
	day = stoi(trim(str.substr(0, str.find(','))));

	str = str.erase(0, str.find(',') + 1);
	hour = stoi(trim(str.substr(0, str.find('\n'))));
}

std::string Reservation::trim(const std::string& str)
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

std::ostream& sdds::operator<<(std::ostream& os, const sdds::Reservation& obj)
{
	std::string emailStr = "<" + obj.email + ">";

	os << "Reservation " << std::setw(10) << std::right << obj.id << ": ";
	os << std::setw(20) << std::right << obj.name << "  ";
	os << std::setw(20) << std::left << emailStr;
	os << "    ";

	if (obj.hour >= 6 && obj.hour <= 9)
	{
		os << "Breakfast on day " << obj.day; 
	}
	else if (obj.hour >= 11 && obj.hour <= 15)
	{
		os << "Lunch on day " << obj.day;
	}
	else if (obj.hour >= 17 && obj.hour <= 21)
	{
		os << "Dinner on day " << obj.day;
	}
	else
		os << "Drinks on day " << obj.day;

	os << " @ " << obj.hour << ":00 for " << obj.numOfPeople;

	if (obj.numOfPeople == 1)
		os << " person." << std::endl;
	else
		os << " people." << std::endl;

	return os;
}

