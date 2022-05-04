/* Citation and Sources...
Final Project Milestone 04
Module: TriagePatient
Filename: TriagePatient.h
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

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"
namespace sdds {

	class TriagePatient : public Patient
	{
		char* symptoms;
	public:
		TriagePatient();
		char type()const;
		~TriagePatient();
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};

}
#endif // !SDDS_TRIAGEPATIENT_H


