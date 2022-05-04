//Workshop 03 - Templates
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 02, 2021
//SetSummable.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SETSUMMABLE_H
#define SETSUMMABLE_H

#include "Set.h"
#include "PairSummable.h"

namespace sdds {

	template<unsigned int N, typename T>
	class SetSummable : public Set<N, T> {
	public:

		T accumulate(const std::string& filter) const {
			T accum(filter);

			bool checker = false;

			for (unsigned int i = 0; i < this->size(); i++)
			{
				if (accum.isCompatibleWith(this->get(i)))
				{
					accum += this->get(i);
					checker = true;
				}					
			}

			if(!checker)
				accum.ResetInitial();

			T accum2(filter);

			accum.ResetInitial();

			return accum2;
		}
			
	};

}

#endif

