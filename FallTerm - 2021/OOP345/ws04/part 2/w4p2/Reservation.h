//Workshop 04 - Containers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 10, 2021
//Reservation.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.


#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

namespace sdds {

	class Reservation {
		std::string id;
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
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& obj);
	};

	std::ostream& operator<<(std::ostream& os, const Reservation& obj);
}

#endif
