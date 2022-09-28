/* Citation and Sources...
Final Project Milestone 03
Module: Patient
Filename: Patient.cpp
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

#include <string>
#include <cstring>
#include "Ticket.h"
#include "Patient.h"
#include "utils.h"

using namespace std;
namespace sdds {

	Patient::Patient(int num, bool IO) : ticket(num), p_fileIO(IO)
	{
		p_name = nullptr;
		
	}

	Patient::~Patient()
	{
		delete[] p_name;
		p_name = nullptr;
	}

	bool Patient::fileIO()const
	{
		return p_fileIO;
	}

	void Patient::fileIO(bool value)
	{
		p_fileIO = value;
	}

	bool Patient::operator==(char ch)const
	{
		bool rtn = false;

		if (type() == ch)
		{
			rtn = true;
		}

		return rtn;
	}

	bool Patient::operator==(const Patient& obj)const
	{
		bool rtn = false;

		if (this->type() == obj.type())
		{
			rtn = true;
		}

		return rtn;
	}

	void Patient::setArrivalTime()
	{
		ticket.resetTime();
	}
			
	Patient::operator Time()const
	{
		return Time(ticket);
	}

	int Patient::number()const
	{
		return ticket.number();
	}

	ostream& Patient::csvWrite(ostream& ostr)const
	{
		ostr << type() << ',' << p_name << ',' << OHIP << ',';
		ticket.csvWrite(ostr);
		return ostr;
	}

	istream& Patient::csvRead(istream& istr)
	{
		string name;

		delete[] p_name;
		p_name = nullptr;

		p_name = getcstr(nullptr, istr, ',');

		istr >> OHIP;
		istr.ignore();

		ticket.csvRead(istr);
		return istr;
	}

	ostream& Patient::write(ostream& ostr)const
	{
		ostr << ticket << endl;

		for (int i = 0; p_name[i] && i < 25; i++) ostr << p_name[i];

		ostr << ", OHIP: " << OHIP;

		return ostr;
	}

	istream& Patient::read(istream& istr)
	{
		delete[] p_name;
		p_name = nullptr;

		p_name = getcstr("Name: ", istr, '\n');
		

		OHIP = getInt(100000000, 999999999, istr, "OHIP:", "Invalid OHIP Number, ");

		return istr;
	}

}