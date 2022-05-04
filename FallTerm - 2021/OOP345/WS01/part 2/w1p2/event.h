#pragma once
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14
//event.h
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Sep. 12, 2021

extern unsigned int g_sysClock;

namespace sdds {
	class Event {
		char* desc;
		unsigned int startTime;
	public:
		Event();
		Event(const Event& obj);
		Event& operator=(const Event& obj);
		~Event();
		void display()const;
		void set(char arr[] = nullptr);
	};
}

