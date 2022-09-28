//Workshop 03 - Templates
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 02, 2021
//Pair.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef PAIR_H
#define PAIR_H

namespace sdds {

	template<typename V, typename K>
	class Pair {
		V m_value;
		K m_key;
	public:
		Pair(){}

		Pair(const K& key, const V& value) {			
			m_value = value;
			m_key = key;
		}

		const V& value() const {
			return m_value;
		}

		const K& key() const {
			return m_key;
		}

		virtual void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		}

	};

	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}

}

#endif
