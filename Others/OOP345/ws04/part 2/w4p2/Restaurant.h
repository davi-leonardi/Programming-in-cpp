//Workshop 04 - Containers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 10, 2021
//Restaurant.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Reservation.h"

namespace sdds {

	class Restaurant {
		Reservation* reservation = nullptr ;
		size_t numOfReservations = 0u;
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& obj);
		~Restaurant();
		Restaurant& operator=(const Restaurant& obj);
		Restaurant(Restaurant&& src)noexcept;
		Restaurant& operator=(Restaurant&& src)noexcept;
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& obj);
	};

	std::ostream& operator<<(std::ostream& os, const sdds::Restaurant& obj);

}

#endif
