//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 24, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include <iostream>

#include "LblShape.h"

namespace sdds {

	class Rectangle : public LblShape
	{
		unsigned int m_width;
		unsigned int m_heigth;
	public:
		Rectangle();
		Rectangle(const char*, unsigned int, unsigned int);
		void getSpecs(std::istream&);
		void draw(std::ostream&)const;
	};

	std::ostream& operator<<(std::ostream&, const Rectangle&);
	std::istream& operator>>(std::istream&, Rectangle&);
}
#endif