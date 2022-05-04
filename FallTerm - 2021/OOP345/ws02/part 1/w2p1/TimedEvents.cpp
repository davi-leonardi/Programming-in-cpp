#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

using namespace sdds;

TimedEvents::TimedEvents()
{
	numRecords = 0u;
	event->name = {};
	event->unitsOfTime = {};
	event->duration = {};

	startTime = {};
	endTime = {};
}

void TimedEvents::startClock()
{
	startTime = std::chrono::steady_clock::now();
}

void TimedEvents::stopClock()
{
	endTime = std::chrono::steady_clock::now();
}

void TimedEvents::addEvent(const char* str)
{
	event[numRecords].name = str;
	event[numRecords].unitsOfTime = "nanoseconds";
	event[numRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	numRecords++;
}

std::ostream& sdds::operator<<(std::ostream& os, const sdds::TimedEvents& obj)
{
	os << "--------------------------" << std::endl;
	os << "Execution Times:" << std::endl;
	os << "--------------------------" << std::endl;

	for (unsigned int i = 0u; i < obj.numRecords && i < 10; i++)
	{
		os << "  " << std::setw(21) << obj.event[i].name;
		os << std::right << std::setw(13) << obj.event[i].duration.count();
		os <<  " " << obj.event[i].unitsOfTime << std::endl;
	}

	os << "--------------------------" << std::endl;

	return os;
}

