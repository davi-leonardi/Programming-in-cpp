#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include "SongCollection.h"

using namespace sdds;

SongCollection::SongCollection(const char* filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		throw "Incorrect filename";
	}
	else
	{
		std::string record = "";
		while(file)
		{
			Song song;

			getline(file, record, '\n');

			if (record != "")
			{
				song.m_title = trim(record.substr(0, 25));
				record.erase(0, 25);

				song.m_artist = trim(record.substr(0, 25));
				record.erase(0, 25);

				song.m_album = trim(record.substr(0, 25));
				record.erase(0, 25);

				song.m_year = stoul(trim(record.substr(0, 5)));
				record.erase(0, 5);

				song.m_length = stoul(trim(record.substr(0, 5)));
				record.erase(0, 5);

				song.m_price = stod(trim(record.substr(0, 5)));
				record.clear();
				m_songs.push_back(song);
			}
		}
	}
}

void SongCollection::display(std::ostream& out) const
{
	std::for_each(m_songs.begin(), m_songs.end(), [&](const Song& song) {out << song; });
}

std::ostream& sdds::operator<<(std::ostream& out, const Song& theSong)
{
	int minutes = theSong.m_length / 60;
	int seconds = theSong.m_length % 60;

	out << "| " << std::left << std::setw(20) << theSong.m_title << " | ";
	out << std::setw(15) << theSong.m_artist << " | ";
	out << std::setw(20) << theSong.m_album << " | ";
	out << std::right << std::setw(6);

	if (theSong.m_year == 0) out << "" << " | ";
	else
		out << theSong.m_year << " | ";

	out << minutes << ":" << std::setfill('0') << std::setw(2)  << seconds << " | ";
	out << std::setfill(' ');
	out << theSong.m_price << " |" << std::endl;

	return out;
}

std::string SongCollection::trim(const std::string str)
{
	std::string rtn = "";

	size_t ltrimIndex = str.find_first_not_of(' ');

	if (ltrimIndex != std::string::npos)
	{
		size_t rtrimIndex = (str.find_last_not_of(' ') - ltrimIndex);
		rtn = str.substr(ltrimIndex, rtrimIndex + 1);
	}
	else
	{
		rtn = "00";
	}

	return rtn;
}