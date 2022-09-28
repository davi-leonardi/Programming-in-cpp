#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

using namespace sdds;

Book::Book()
{
	m_author = "";
	m_title = "";
	m_country = "";
	m_year = 0u;
	m_price = 0.00;
	m_summary = "";
}

Book::Book(const std::string& strBook)
{
	std::string str = " ";
	str = strBook;
	m_price = 0.00;
	m_year = 0u;
	std::string x = "", z = "";


	m_author = trim(str.substr(0, str.find(',')));

	str = str.erase(0, str.find(',') + 1);
	m_title = trim(str.substr(0, str.find(',')));

	str = str.erase(0, str.find(',') + 1);
	m_country = trim(str.substr(0, str.find(',')));

	str = str.erase(0, str.find(',') + 1);
	m_price =  stod(trim(str.substr(0, str.find(','))));		// <-- error

	str = str.erase(0, str.find(',') + 1);
	m_year =  stoul(trim(str.substr(0, str.find(','))));		// <-- error

	str = str.erase(0, str.find(',') + 1);
	m_summary = trim(str.substr(0, str.find('\n')));
}

std::string Book::trim(const std::string& str)
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

const std::string& Book::title() const
{
	return m_title;
}

const std::string& Book::country() const
{
	return m_country;
}

const size_t& Book::year() const
{
	return m_year;
}

double& Book::price()
{
	return m_price;
}

std::ostream& sdds::operator<<(std::ostream& os, const Book& obj)
{
	os << std::right << std::setw(20) << obj.m_author << " | ";
	os << std::setw(22) << obj.m_title << " | ";
	os << std::setw(5) << obj.m_country << " | ";
	os << std::setw(4) << obj.m_year << " | ";
	os << std::setw(6) << std::fixed << std::setprecision(2) << obj.m_price << " | ";
	os << obj.m_summary << std::endl;

	return os;
}
