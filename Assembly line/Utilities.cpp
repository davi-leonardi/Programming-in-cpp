// Name: Davi Leonardi Mathey
// Seneca Student ID: 154979199
// Seneca email: dleonardi-mathey@myseneca.ca
// Date of completion: Dec 2, 2021

// I confirm that I am the only author of this file and the content was created entirely by me.

#include <iostream>
#include <string>
#include <sstream>
#include "Utilities.h"

using namespace sdds;

char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t newWidth)
{
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string token = "";

	if (more)
	{
		size_t delimiter = 0u;

		if (str[next_pos] == m_delimiter)
		{
			more = false;
			throw "Delimiter found at next_pos";
		}

		delimiter = str.find(m_delimiter, next_pos);
		token = str.substr(next_pos, (delimiter - next_pos));
		if (delimiter < 100) next_pos = ++delimiter;
		else
			more = false;

		if (m_widthField < token.size()) setFieldWidth(token.size());
	}

	return token;		
}

char Utilities::getDelimiter()
{
	return m_delimiter;
}

void Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter;
}