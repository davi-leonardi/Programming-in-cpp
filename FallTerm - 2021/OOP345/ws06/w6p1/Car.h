#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

namespace sdds {

	enum class Condition {n, u, b};

	class Car : public Vehicle {
		std::string m_maker;
		Condition m_condition;
		double m_topSpeed;
		std::string trim(const std::string& str);
	public:
		Car(std::istream&);
		double topSpeed() const;
		void display(std::ostream&) const;
		std::string condition() const;
	};

}

#endif
