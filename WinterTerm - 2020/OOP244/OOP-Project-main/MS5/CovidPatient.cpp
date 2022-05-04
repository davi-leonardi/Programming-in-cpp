/* Citation and Sources...
Final Project Milestone 05
Module: CovidPatient
Filename: CovidPatient.cpp
Version 1.0
Author:	Davi Leonardi Mathey
ID: 154979199
E-mail: dleonardi-mathey@myseneca.ca
-----------------------------------------------------------
Date        Reason
2021/04/10  Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "CovidPatient.h"

using namespace std;
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
	   nextCovidTicket += 1;
   }

   char CovidPatient::type()const
   {
	   return 'C';
   }

   istream& CovidPatient::csvRead(istream& istr)
   {
	   Patient::csvRead(istr);

	   nextCovidTicket = Patient::number() + 1;

	   return istr;
   }

   ostream& CovidPatient::write(ostream& ostr)const
   {
	   if (fileIO())
	   {
		   Patient::csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "COVID TEST" << endl;

		   Patient::write(ostr);
		   ostr << endl;
	   }

	   return ostr;
   }

   istream& CovidPatient::read(istream& istr)
   {
	   if (fileIO())
	   {
		   csvRead(istr);
	   }
	   else
	   {
		   Patient::read(istr);
	   }

	   return istr;
   }

}