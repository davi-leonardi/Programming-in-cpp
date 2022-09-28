/* Citation and Sources...
Final Project Milestone 02
Module: IOAble
Filename: IOAble.h
Version 1.0
Author:	Davi Leonardi Mathey
ID: 154979199
E-mail: dleonardi-mathey@myseneca.ca
-----------------------------------------------------------
Date        Reason
2021/03/22  Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
using namespace std;
namespace sdds {

	class IOAble {
	public:
		 virtual ostream& csvWrite(std::ostream& ostr)const = 0;
		 virtual istream& csvRead(std::istream& istr) = 0;
		 virtual ostream& write(ostream& ostr)const = 0;
		 virtual istream& read(istream& istr) = 0;
		 virtual ~IOAble() {};
	};

	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
	std::istream& operator>>(std::istream& istr, IOAble& obj);

}
#endif