// Workshop 2 - Copy and Move Semantics
//StringSet.h
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 02, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef STRINGSET_H
#define STRINGSET_H

#include<string>

namespace sdds {

	class StringSet {
		std::string* records = nullptr;
		unsigned int numStr = 0u;
	public:
		StringSet();
		StringSet(const char* arr);
		StringSet(const StringSet& obj);
		StringSet& operator=(const StringSet& obj);
		~StringSet();
		size_t size()const;
		std::string operator[](size_t)const;	
		StringSet(StringSet&& src)noexcept;
		StringSet& operator=(StringSet&& src)noexcept;		
	};
}

#endif
