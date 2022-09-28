//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 24, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include <iostream>

#include "LblShape.h"

namespace sdds {

	class Line : public LblShape
	{
		int m_length;
	public:
		Line();
		Line(const char*, int);
		void getSpecs(std::istream&);
		void draw(std::ostream&)const;
	};

	std::ostream& operator<<(std::ostream&, const Line&);
	std::istream& operator>>(std::istream&, Line&);
}
#endif