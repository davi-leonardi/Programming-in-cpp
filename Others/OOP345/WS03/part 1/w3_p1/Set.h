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
