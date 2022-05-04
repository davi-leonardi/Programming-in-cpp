/* Citation and Sources...
Final Project Milestone 03
Module: Patient
Filename: Patient.h
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

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

#include "IOAble.h"
#include "Ticket.h"
#include "Time.h"
namespace sdds {

	class Patient : public IOAble
	{
		char* p_name;
		int OHIP;
		Ticket ticket;
		bool p_fileIO;
	public:
		Patient(int = 0, bool = false);
		~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool);
		bool operator==(char)const;
		bool operator==(const Patient&)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};

}
#endif