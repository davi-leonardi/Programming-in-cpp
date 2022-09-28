// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14
//event.cpp
//Name: Davi Leonardi Mathey
//ID: 154979199

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "event.h"

using namespace sdds;
unsigned int g_sysClock = 0;

Event::Event()
{
	desc[0] = '\0';
	startTime = 0;
}

void Event::display()const
{
	static int counter = 1;
	std::cout << counter << ". ";

	unsigned int timeTotal = startTime, hh = 0, mm = 0, ss = 0;

	hh = timeTotal / 3600;
	timeTotal %= 3600;
	mm = timeTotal / 60;
	timeTotal %= 60;
	ss = timeTotal;

	if (desc[0] != '\0')
	{
		std::cout << std::setfill('0') << std::setw(2) << hh << ':';
		std::cout << std::setfill('0') << std::setw(2) << mm << ':';
		std::cout << std::setfill('0') << std::setw(2) << ss;
		std::cout << " => " << desc << std::endl;
	}
	else
		std::cout << "| No Event |" << std::endl;

	counter++;
}

void Event::set(char arr[])
{
	if (arr != nullptr && arr[0] != '\0')
	{
		strcpy(desc, arr);
		startTime = g_sysClock;	
	}
	else
	{
		desc[0] = '\0';
		startTime = 0;
	}

}