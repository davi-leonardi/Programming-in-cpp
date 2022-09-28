/* Citation and Sources...
Final Project Milestone 04
Module: TriagePatient
Filename: TriagePatient.cpp
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

#include <iostream>
#include "TriagePatient.h"
#include "utils.h"

using namespace std;
namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket)
   {
	   symptoms = nullptr;

	   nextTriageTicket += 1;
   }

   char TriagePatient::type()const
   {
	   return 'T';
   }

   ostream& TriagePatient::csvWrite(ostream& ostr)const
   {
	   Patient::csvWrite(ostr);
	   ostr << ',' << symptoms;

	   return ostr;
   }

   istream& TriagePatient::csvRead(istream& istr)
   {
	   delete[] symptoms;
	   symptoms = nullptr;

	   Patient::csvRead(istr);
	   istr.ignore();

	   symptoms = getcstr(nullptr, istr, '\n');

	   nextTriageTicket = Patient::number() + 1;

	   return istr;
   }

   ostream& TriagePatient::write(ostream& ostr)const
   {
	   if (fileIO())
	   {
		   csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "TRIAGE" << endl;

		   Patient::write(ostr);
		   ostr << endl;

		   ostr << "Symptoms: " << symptoms << endl;

		   
	   }

	   return ostr;
   }

   istream& TriagePatient::read(istream& istr)
   {
	   if (fileIO())
	   {
		   csvRead(istr);
	   }
	   else
	   {
		   delete[] symptoms;
		   symptoms = nullptr;

		   Patient::read(istr);

		   symptoms = getcstr("Symptoms: ", istr, '\n');
	   }

	   return istr;
   }

   TriagePatient::~TriagePatient()
   {
	   delete[] symptoms;
	   symptoms = nullptr;
   }

}