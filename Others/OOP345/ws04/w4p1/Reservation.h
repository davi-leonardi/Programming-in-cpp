#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

namespace sdds {

	class Reservation {
		char* id;
		std::string name;
		std::string email;
		size_t numOfPeople;
		int day;
		int hour;
		std::string trim(const std::string& str);

	public:
		Reservation();
		Reservation(const Reservation& obj);
		Reservation& operator=(const Reservation& obj);
		//~Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& obj);
	};

	std::ostream& operator<<(std::ostream& os, const Reservation& obj);

}

#endif
