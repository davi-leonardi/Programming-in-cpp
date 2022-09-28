//Workshop 06 - STL Algorithms
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 13, 2021
//SongCollection.h

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SONGCOLLECTION_H
#define	SONGCOLLECTION_H

#include <iostream>
#include <vector>
#include <list>

namespace sdds {

	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		size_t m_year;
		size_t m_length;
	};
	
	class SongCollection {
		std::vector<Song> m_songs;
		std::string trim(const std::string);
	public:
		SongCollection(const char*);
		void display(std::ostream&) const;
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(std::string) const;
		std::list<Song> getSongsForArtist(std::string) const;
	};

	void timeFormat(std::ostream&, size_t = 0u);
	std::ostream& operator<<(std::ostream&, const Song&);
}

#endif
