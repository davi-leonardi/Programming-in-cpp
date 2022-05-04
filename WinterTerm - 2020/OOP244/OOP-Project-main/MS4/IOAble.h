/* Citation and Sources...
Final Project Milestone 04
Module: IOAble
Filename: IOAble.h
Version 1.0
Author:	Davi Leonardi Mathey
ID: 154979199
E-mail: dleonardi-mathey@myseneca.ca
-----------------------------------------------------------
Date        Reason
2021/03/31  Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>

namespace sdds {

	class IOAble {
	public:
		 virtual std::ostream& csvWrite(std::ostream& ostr)const = 0;
		 virtual std::istream& csvRead(std::istream& istr) = 0;
		 virtual std::ostream& write(std::ostream& ostr)const = 0;
		 virtual std::istream& read(std::istream& istr) = 0;
		 virtual ~IOAble() {};
	};

	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
	std::istream& operator>>(std::istream& istr, IOAble& obj);

}
#endif