// Name: Davi Leonardi Mathey
// Seneca Student ID: 154979199
// Seneca email: dleonardi-mathey@myseneca.ca
// Date of completion: Nov 16, 2021

// I confirm that I am the only author of this file and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H

#include <iostream>

namespace sdds {

	class Station {
		int m_id;
		std::string m_name;
		std::string m_description;
		size_t m_serialNumber;
		size_t m_quantity;
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string&);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

}

#endif
