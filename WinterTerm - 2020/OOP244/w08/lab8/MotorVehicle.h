#pragma once
//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 17, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_

namespace sdds {
	class MotorVehicle {
		char m_plate[9];
		char m_address[64];
		int m_year;
	public:
		MotorVehicle(const char* plate, int year);		
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	protected:
		char* getAddress();
		char* getPlate();
		int& getYear();
	};

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& obj);
	std::istream& operator>>(std::istream& istr, MotorVehicle& obj);

}

#endif // SDDS_MOTORVEHICLE_H_