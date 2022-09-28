//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 24, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string>

#include "LblShape.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"

using namespace std;
namespace sdds {

	const char* LblShape::label()const
	{
		return m_label;
	}

	LblShape::LblShape()
	{
		m_label = nullptr;
	}

	LblShape::LblShape(const char* cstring)
	{
		setLabel(cstring);
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::setLabel(const char* cstr)
	{

		delete[] m_label;
		m_label = nullptr;

		m_label = new char[strlen(cstr) + 1];
		strcpy(m_label, cstr);
		
	}

	void LblShape::getSpecs(std::istream& cstring)
	{
		string str;

		getline(cstring, str, ',');

		setLabel(str.c_str());
	}

}