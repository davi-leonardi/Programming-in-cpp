//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 24, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include <iostream>
#include "Shape.h"

namespace sdds {

	class Shape;

	class LblShape : public Shape {
		char* m_label = nullptr;
	protected:
		const char* label()const;
	public:
		LblShape();
		LblShape(const char* cstring);
		~LblShape();
		void setLabel(const char*);
		void getSpecs(std::istream&);
	};

}
#endif