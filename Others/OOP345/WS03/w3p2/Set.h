//Workshop 03 - Templates
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 02, 2021
//Set.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SET_H
#define SET_H

namespace sdds {

	template<unsigned int N, typename T>
	class Set {	
		T collection[N] = {};
		unsigned int m_size = 0;
	public:

		size_t size() const {
			return m_size;
		}

		const T& get(size_t idx) const{
			return collection[idx];
		}

		void operator+=(const T& item) {
			if (m_size < N)
			{
				collection[m_size] = item;
				m_size++;
			}
		}
	};

}

#endif
