/* Citation and Sources...
Final Project Milestone 03
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author:	Davi Leonardi Mathey
ID: 154979199
E-mail: dleonardi-mathey@myseneca.ca
-----------------------------------------------------------
Date        Reason
2021/03/27  Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "IOAble.h"

using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj)
	{
		return obj.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, IOAble& obj)
	{
		return obj.read(istr);
	}

}