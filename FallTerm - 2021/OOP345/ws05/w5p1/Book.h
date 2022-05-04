#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

namespace sdds {

	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_summary;
		std::string trim(const std::string& str);
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& obj);
	};

	std::ostream& operator<<(std::ostream& os, const Book& obj);

}

#endif
