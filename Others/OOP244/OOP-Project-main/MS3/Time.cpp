/* Citation and Sources...
Final Project Milestone 03
Module: Time
Filename: Time.cpp
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

#include "Time.h"
#include "utils.h"
#include <string>
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
		string str, h, m;
		int hours = 0, mins = 0;
		bool fail = false;

		istr >> str;

		if (str.find(':') == string::npos)
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			h = str.substr(0, str.find(':'));
			m = str.erase(0, str.find(':') + 1);

			for (unsigned int i = 0; i < h.length(); i++)
			{
				if (!isdigit(h[i])) fail = true;
			}

			for (unsigned int x = 0; x < m.length(); x++)
			{
				if (!isdigit(m[x])) fail = true;
			}

			if (!fail)
			{
				hours = stoi(h);
				mins = stoi(m);


				if (hours <= 0 || mins <= 0)
				{
					fail = true;
				}
				else
				{
					m_min = (hours * 60) + mins;
				}
			}

		}

		if (fail) istr.setstate(ios::failbit);

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