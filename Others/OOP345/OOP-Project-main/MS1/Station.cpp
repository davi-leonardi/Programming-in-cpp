// Name: Davi Leonardi Mathey
// Seneca Student ID: 154979199
// Seneca email: dleonardi-mathey@myseneca.ca
// Date of completion: Nov 16, 2021

// I confirm that I am the only author of this file and the content was created entirely by me.

#include <iomanip>
#include <string>
#include <sstream>
#include "Station.h"
#include "Utilities.h"

using namespace sdds;

size_t Station::m_widthField = 0u;
size_t Station::id_generator = 0u;

Station::Station(const std::string& str)
{
	Utilities utilities;
	bool more = true;
	size_t nextPos = 0u;

	std::stringstream stream, sstream;

	m_name = utilities.extractToken(str, nextPos, more);
	stream << utilities.extractToken(str, nextPos, more);
	stream >> m_serialNumber;
	sstream << utilities.extractToken(str, nextPos, more);
	sstream >> m_quantity;
	
	if (m_widthField < utilities.getFieldWidth()) m_widthField = utilities.getFieldWidth();

	m_description = utilities.extractToken(str, nextPos, more);
	m_id = ++id_generator;
}

const std::string& Station::getItemName() const
{
	return m_name;
}

size_t Station::getNextSerialNumber()
{
	return m_serialNumber++;
}

size_t Station::getQuantity() const
{
	return m_quantity;
}

void Station::updateQuantity()
{
	if (m_quantity >= 1) m_quantity--;
	else
		m_quantity = 0;
}

void Station::display(std::ostream& os, bool full) const
{
	os << "[" << std::setfill('0') << std::setw(3) << std::right << m_id << "]" << std::setfill(' ');
	os << " Item: " << std::setw(m_widthField) << std::left << m_name;
	os << " [" << std::setfill('0') << std::setw(6) << std::right << m_serialNumber << "]" << std::setfill(' ');

	if (full)
	{
		os << " Quantity: " << std::left << std::setw(m_widthField) << m_quantity;
		os << " Description: " << m_description;
	}

	os << std::endl;
}
