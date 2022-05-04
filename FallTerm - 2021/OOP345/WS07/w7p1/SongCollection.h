#ifndef SONGCOLLECTION_H
#define	SONGCOLLECTION_H

#include <iostream>
#include <vector>

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
		std::string trim(const std::string str);
	public:
		SongCollection(const char*);
		void display(std::ostream& out) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}

#endif
