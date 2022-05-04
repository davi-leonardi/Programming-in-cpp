#pragma once
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14
//event.h
//Name: Davi Leonardi Mathey
//ID: 154979199

extern unsigned int g_sysClock;

namespace sdds {
	class Event {
		char desc[128];
		unsigned int startTime;
	public:
		Event();
		void display()const;
		void set(char arr[] = nullptr);
	};
}

