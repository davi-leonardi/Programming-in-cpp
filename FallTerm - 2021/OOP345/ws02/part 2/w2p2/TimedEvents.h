// Workshop 2 - Copy and Move Semantics
//TimedEvent.h
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 02, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef TIMEDEVENTS_H
#define TIMEDEVENTS_H

#include <string>
#include <chrono>

namespace sdds {

	struct Event {
		std::string name = {};
		std::string unitsOfTime = {};
		std::chrono::steady_clock::duration duration = {};
	};

	class TimedEvents {
		unsigned int numRecords;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		Event event[10];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* str);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& obj);
	};

	std::ostream& operator<<(std::ostream& os, const TimedEvents& obj);

}

#endif