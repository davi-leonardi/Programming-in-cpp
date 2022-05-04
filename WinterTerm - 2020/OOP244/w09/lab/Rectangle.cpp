//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 24, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <cstring>
#include <string>

#include "LblShape.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Line.h"

using namespace std;
namespace sdds {

	Rectangle::Rectangle() : LblShape()
	{
		m_width = 0;
		m_heigth = 0;
	}

	Rectangle::Rectangle(const char* cstring, unsigned int width, unsigned int heigth) : LblShape(cstring)
	{
		if (heigth < 3 || width < (strlen(label()) + 2))
		{
			m_width = 0;
			m_heigth = 0;
		}
		else
		{
			m_width = width;
			m_heigth = heigth;
		}
	}

	void Rectangle::getSpecs(std::istream& is)
	{
		string width, heigth;

		LblShape::getSpecs(is);
		getline(is, width, ',');
		getline(is, heigth, '\n');

		m_width = stoi(width);
		m_heigth = stoi(heigth);
	}

	void Rectangle::draw(std::ostream& os)const
	{
		if (m_width != 0 && m_heigth != 0)
		{
			os << '+';
			for (unsigned int i = 0; i < (m_width - 2); i++) os << '-';
			os << '+' << endl;

			os << '|';
			os.width(m_width - 2);
			os << left << label();
			os << '|' << endl;

			for (unsigned int z = 0; z < (m_heigth - 3); z++)
			{
				os << '|';
				os.width(m_width - 2);
				os << ' ';
				os << '|' << endl;
			}

			os << '+';
			for (unsigned int i = 0; i < (m_width - 2); i++) os << '-';
			os << '+';

		}
	}

	ostream& operator<<(ostream& ostr, const Rectangle& obj)
	{
		obj.draw(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Rectangle& obj)
	{
		obj.getSpecs(istr);
		return istr;
	}

}