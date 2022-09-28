/* Citation and Sources...
Final Project Milestone 02
Module: Menu
Filename: Menu.cpp
Version 1.0
Author:	Davi Leonardi Mathey
ID: 154979199
E-mail: dleonardi-mathey@myseneca.ca
-----------------------------------------------------------
Date        Reason
2021/03/22  Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds {

	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);

		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	Menu& Menu::operator=(Menu& src)
	{
		if (this != &src)
		{
			m_noOfSel = src.m_noOfSel;

			delete[] m_text;

			if (src.m_text != nullptr)
			{
				m_text = new char[strlen(src.m_text) + 1];
				strcpy(m_text, src.m_text);
			}
			else
			{
				m_text = nullptr;
			}
		}			
		
		return *this;
	}

	void Menu::display()const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");
		return Selection;
	}

}