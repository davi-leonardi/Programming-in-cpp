//Workshop 03 - Templates
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 02, 2021
//PairSummable.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef PAIRSUMMABLE_H
#define PAIRSUMMABLE_H

#include "Pair.h"
#include <iostream>
#include <iomanip>

namespace sdds {

	template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V initial;
		static size_t minWidth;
	public:
		PairSummable(){};

		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value){
			if (key.size() && key.size() > minWidth) minWidth = key.size();
		}

		virtual void display(std::ostream& os) const {
			os << std::left << std::setw(minWidth);
			Pair<V, K>::display(os);
			os << std::right;
		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const{
			bool rtn = false;
			if (this->key() == b.key()) rtn = true;

			return rtn;
		}

		PairSummable<V, K>& operator+=(const PairSummable<V, K>& obj) {

				initial += obj.value();

			return *this;
		}

		void ResetInitial() {
			initial = {};
		}

	};

	template<typename V, typename K>
	V PairSummable<V, K>::initial = {};
	template<typename V, typename K>
	size_t PairSummable<V, K>::minWidth = 0;

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& obj)
	{

		if (initial != "")
			initial += ", " + obj.value();
		else
			initial = obj.value();

		return *this;
	}

}

#endif
