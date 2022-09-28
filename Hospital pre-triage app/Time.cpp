/* Citation and Sources...
Final Project Milestone 05
Module: Time
Filename: Time.cpp
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

#include <iostream>
#include <string>
#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds {

	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	ostream& Time::write(ostream& ostr) const
	{
		int digits = 0;
		int hours = 0;
		int mins = 0;

		if (m_min % 60 == 0)
		{
			hours = m_min / 60;
			mins = 0;
		}
		else
		{
			hours = m_min / 60;
			mins = m_min % 60;
		}

		int h = hours;
		while (h) {
			h /= 10;
			digits++;
		}

		if (digits == 1 || hours == 0)
		{
			ostr.width(2);
			ostr.fill('0');
			ostr << hours << ':';
		}
		else
		{
			ostr << hours << ':';
		}

		digits = 0;
		int m = mins;
		while (m) {
			m /= 10;
			digits++;
		}

		if (digits == 1 || mins == 0)
		{
			ostr.width(2);
			ostr.fill('0');
			ostr << mins;
		}
		else
		{
			ostr << mins;
		}

		return ostr;
	}	

	std::istream& Time::read(std::istream& istr)
	{
		int hrs = 0;
		int min = 0;
		char del;
		bool fail = false;

		istr >> hrs >> del >> min;

		if (hrs < 0)
		{
			istr.setstate(ios::failbit);
			fail = true;
		}					

		if (del != ':' && !fail)
		{
			istr.setstate(ios::failbit);
			fail = true;
		}

		if (min < 0 && !fail)istr.setstate(ios::failbit);		

		m_min = (hrs * 60) + min;

		return istr;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (m_min > D.m_min)
		{
			m_min -= D.m_min;
		}
		else
		{
			while (m_min < D.m_min)
			{
				m_min += 1440;
			}

			m_min = m_min - D.m_min;
		}

		return *this;
	}

	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;

		return *this;
	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}

	Time Time::operator-(const Time& D)const
	{
		unsigned int newMin = m_min;

		if (m_min > D.m_min)
		{
			newMin -= D.m_min;
		}
		else
		{
			while (newMin < D.m_min)
			{		
				newMin += 1440;			
			} 

			newMin = newMin - D.m_min;
		}

		return newMin;
	}

	Time Time::operator+(const Time& D)const
	{
		unsigned int newMin = m_min;

		newMin += D.m_min;

		return newMin;
	}

	Time& Time::operator *= (unsigned int val)
	{
		m_min *= val;

		return *this;
	}

	Time Time::operator *(unsigned int val)const
	{
		unsigned int newMin = m_min;

		newMin *= val;

		return newMin;
	}

	Time& Time::operator /= (unsigned int val)
	{
		m_min /= val;

		return *this;
	}

	Time Time::operator /(unsigned int val)const
	{
		unsigned int newMin = m_min;

		newMin /= val;

		return newMin;
	}

	ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}
	
	Time::operator int()const
	{		
		return int(m_min);
	}

	Time::operator unsigned int()const
	{
		return m_min;
	}

}