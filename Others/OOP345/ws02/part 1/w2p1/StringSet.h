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
	};

}

#endif
