//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 24, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include "Shape.h"
#include "LblShape.h"
#include "Line.h"
#include "Rectangle.h"

using namespace std;
namespace sdds {

	ostream& operator<<(std::ostream& ostr, const Shape& obj)
	{
		obj.draw(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Shape& obj)
	{
		obj.getSpecs(istr);
		return istr;
	}

}