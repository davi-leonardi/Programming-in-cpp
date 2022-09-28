//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF 

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

	Canister::Canister()
	{
		setToDefault();
	}

	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_diameter = 10.00;
		m_hieght = 13.00;
		m_contentVolume = 0.00;
		m_usable = true;
	}

	bool Canister::isEmpty()const
	{
		bool rtn = false;

		if (m_contentVolume < 0.00001)
		{
			rtn = true;
		}

		return rtn;
	}

	bool Canister::hasSameContent(const Canister& C)const
	{
		bool rtn = false;

		if (!strCmp(this->m_contentName, C.m_contentName) && this->m_contentName != nullptr)
		{
			rtn = true;
		}

		return rtn;
	}

	void Canister::setName(const char* Cstr)
	{
		if (Cstr != NULL && m_usable == true)
		{
			delete[] m_contentName;

			m_contentName = new char[strLen(Cstr) + 1];

			strCpy(m_contentName, Cstr);
		}
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double hieght, double diameter,
		const char* contentName)
	{	
		setToDefault();

		if ((hieght >= 10 && hieght <= 40) && (diameter >= 10 && diameter <= 30))
		{
			m_hieght = hieght;
			m_diameter = diameter;
			m_contentVolume = 0.00;

			setName(contentName);
		}
		else
		{
			m_usable = false;
		}
	}

	void Canister::clear()
	{
		if (!m_usable)
		{
			delete[] m_contentName;			
			m_contentName = nullptr;
			m_contentVolume = 0.00;
			m_usable = true;
		}
		
	}

	double Canister::capacity()const
	{
		double pi = 3.14159265;

		return (pi * (m_hieght - 0.267) * (m_diameter / 2) * (m_diameter / 2));
	}

	double Canister::volume()const
	{
		return m_contentVolume;
	}
   
	Canister& Canister::setContent(const char* contentName)
	{
		
		if (contentName == nullptr)
		{
			m_usable = false;
		}
		else if (isEmpty())
		{
			setName(contentName);
		}
		else if (!hasSameContent(contentName))
		{
			m_usable = false;
		}
		
		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (m_usable && quantity > 0.00 && (quantity + m_contentVolume) <= capacity())
		{		
			this->m_contentVolume += quantity;
		}
		else
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		setContent(C.m_contentName);

		if (C.m_contentVolume > capacity() - volume())
		{
			C.m_contentVolume -= capacity() - volume();
			this->m_contentVolume = capacity();
		}
		else
		{
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.00;
		}
		return *this;
	}

	std::ostream& Canister::display()const
	{
		cout.width(7);
		cout.setf(ios::fixed);
		cout.precision(1);

		cout <<capacity();

		cout << "cc (";

		cout << m_hieght;

		cout << "x";

		cout << m_diameter;

		cout << ") Canister";
		if (!m_usable)
		{
			cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr)
		{
			cout << " of ";
			cout.width(7);
			cout << right << volume();
			cout << "cc   ";
			cout << m_contentName;
		}
		return cout;
	}

	Canister::~Canister()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
	}
}