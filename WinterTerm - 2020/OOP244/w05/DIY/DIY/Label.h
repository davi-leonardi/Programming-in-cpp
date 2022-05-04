//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#pragma once
#include <iostream>

#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_
namespace sdds 
{
	using namespace std;

	class Label
	{
		char frame[9];
		char* name;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
	};
}
#endif