// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14
//event.cpp
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Sep. 12, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

//#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "event.h"

using namespace sdds;
unsigned int g_sysClock = 0;

Event::Event()
{
	desc = nullptr; 
	startTime = 0;
}

Event::~Event()
{
	delete[] desc;
	desc = nullptr;
}

Event::Event(const Event& obj)
{
	desc = nullptr;

	if (obj.desc != nullptr)
	{
		desc = new char[strlen(obj.desc) + 1];
		strcpy(desc, obj.desc);
	}

	startTime = obj.startTime;
}

Event& Event::operator=(const Event& obj)
{
	if (this != &obj)
	{
		startTime = obj.startTime;

		delete[] desc;

		if (obj.desc != nullptr)
		{
			desc = new char[strlen(obj.desc) + 1];
			strcpy(desc, obj.desc);
		}
		else
			desc = nullptr;		
	}

	return *this;
}

void Event::display()const
{
	static int counter = 1;
	std::cout << std::setfill(' ') << std::setw(2) << counter << ". ";

	unsigned int timeTotal = startTime, hh = 0, mm = 0, ss = 0;

	hh = timeTotal / 3600;
	timeTotal %= 3600;
	mm = timeTotal / 60;
	timeTotal %= 60;
	ss = timeTotal;

	if (desc != nullptr)
	{
		std::cout << std::setfill('0') << std::setw(2) << hh << ':';
		std::cout << std::setfill('0') << std::setw(2) << mm << ':';
		std::cout << std::setfill('0') << std::setw(2) << ss;
		std::cout << " => " << desc << std::endl;
	}
	else
	{
		std::cout << "| No Event |" << std::endl;
	}

	counter++;
}

void Event::set(char arr[])
{

	if (arr != nullptr)
	{
		desc = nullptr;
		desc = new char[strlen(arr) + 1];
		strcpy(desc, arr);

		startTime = g_sysClock;
	}
	else
	{
		desc = nullptr;
		startTime = 0;
	}

}