//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 24, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include "LblShape.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"

using namespace std;
namespace sdds {

	Line::Line() : LblShape()
	{
		m_length = 0;	
	}

	Line::Line(const char* cstring, int num) : LblShape(cstring)
	{
		m_length = num;
	}
	
	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n');
	}

	void Line::draw(std::ostream& os)const
	{
		if (m_length > 0 && label() != NULL)
		{
			os << label() << endl;

			for (int i = 0; i < m_length; i++) os << '=';

		}
	}

	ostream& operator<<(std::ostream& ostr, const Line& obj)
	{
		obj.draw(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Line& obj)
	{
		obj.getSpecs(istr);
		return istr;
	}

}