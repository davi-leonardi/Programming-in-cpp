//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 24, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_

#include <iostream>

namespace sdds {

	class Shape {
	public:
		virtual void draw(std::ostream&)const = 0;
		virtual void getSpecs(std::istream&) = 0;
		virtual ~Shape() {};
	};

	std::ostream& operator<<(std::ostream&, const Shape&);
	std::istream& operator>>(std::istream&, Shape&);
}
#endif