//Workshop 04 - Containers
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Oct 10, 2021
//ConfirmationSender.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef CONFIRMATIONSENDER_H
#define CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {

	class ConfirmationSender {
		const Reservation** resPointers = { nullptr };
		size_t numOfResPointers = 0u;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& obj);
		ConfirmationSender(ConfirmationSender&& src)noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& src)noexcept;
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj);
	};

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj);
}

#endif
