//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#include "Mark.h"
#include<iostream>

namespace sdds {
using namespace std;

	Mark::Mark()
	{
		num = 0;
	}

	Mark::Mark(int n)
	{
		if (n >= 0 && n <= 100)
		{
			num = n;
		}
		else
		{
			num = -1;
		}
	}

	Mark::operator int()const
	{
		int rtn = num;

		if (num < 0 || num > 100)
		{
			rtn = 0;
		}

		return rtn;
	}

	Mark::operator double()const
	{	
		double gpa;

		if (num >= 50 && num < 60)
		{
			gpa = 1.0;
		}
		else if (num >= 60 && num < 70)
		{
			gpa = 2.0;
		}
		else if (num >= 70 && num < 80)
		{
			gpa = 3.0;
		}
		else if (num >= 80 && num <= 100)
		{
			gpa = 4.0;
		}
		else
		{
			gpa = 0.0;
		}

		return gpa;
	}

	Mark::operator char()const
	{
		char letter;

		if (num >= 0 && num < 50)
		{
			letter = 'F';
		}
		else if (num >= 50 && num < 60)
		{
			letter = 'D';
		}
		else if (num >= 60 && num < 70)
		{
			letter = 'C';
		}
		else if (num >= 70 && num < 80)
		{
			letter = 'B';
		}
		else if (num >= 80 && num <= 100)
		{
			letter = 'A';
		}
		else
		{
			letter = 'X';
		}

		return letter;
	}

	Mark& Mark::operator+= (int n)
	{
		if (num >= 0)
		{
			num += n;
		}

		return *this;
	}

	Mark& Mark::operator= (int n)
	{
		if (n >= 0 && n <= 100)
		{
			num = n;
		}
		else
		{
			num = -1;
		}

		return *this;
	}

	int operator+= (int& value, const Mark& obj)
	{

		if (int(obj))
		{
			value += int(obj);
		}

		return value;
	}
}