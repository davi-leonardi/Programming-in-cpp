//Workshop 06 - STL Algorithms
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 13, 2021
//SongCollection.cpp

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>
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
	std::for_each(m_songs.begin(), m_songs.end(), [&](const Song& song) {out << song << std::endl; });
	out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
	out << "| " << std::right << std::setw(77) << "Total Listening Time: ";

	timeFormat(out, std::accumulate(m_songs.begin(), m_songs.end(), 0u, [](const size_t& init, const Song& song2) {return init + song2.m_length; }));

	out << " |\n";
}

std::ostream& sdds::operator<<(std::ostream& out, const Song& theSong)
{
	out << "| " << std::left << std::setw(20) << theSong.m_title << " | ";
	out << std::setw(15) << theSong.m_artist << " | ";
	out << std::setw(20) << theSong.m_album << " | ";
	out << std::right << std::setw(6);

	if (theSong.m_year == 0) out << "" << " | ";
	else
		out << theSong.m_year << " | ";

	timeFormat(out, theSong.m_length);
	out << " | ";

	out << theSong.m_price << " |";

	return out;
}

void sdds::timeFormat(std::ostream& out, size_t length)
{
	int hours, minutes, seconds;

	hours = length / 3600;
	length = length % 3600;
	minutes = length / 60;
	seconds = length % 60;

	if (hours > 0) out << hours << ":";
	if (minutes > 0) out << minutes << ":";
	out << std::setfill('0') << std::setw(2) << seconds << std::setfill(' ');
}

void SongCollection::sort(std::string field)
{
	if (field == "title")
	{
		std::sort(m_songs.begin(), m_songs.end(), [=](const Song& song1, const Song& song2) {return song1.m_title < song2.m_title; });
	}
	else if (field == "album")
	{
		std::sort(m_songs.begin(), m_songs.end(), [=](const Song& song1, const Song& song2) {return song1.m_album < song2.m_album; });
	}
	else
		std::sort(m_songs.begin(), m_songs.end(), [=](const Song& song1, const Song& song2) {return song1.m_length < song2.m_length; });
}

void SongCollection::cleanAlbum()
{
	std::for_each(m_songs.begin(), m_songs.end(), [](Song& song) {if (song.m_album == "[None]") song.m_album = ""; });
}

bool SongCollection::inCollection(std::string name) const
{
	return std::any_of(m_songs.begin(), m_songs.end(), [=](const Song& song) {return song.m_artist == name; });
}

std::list<Song> SongCollection::getSongsForArtist(std::string name) const
{
	std::list<Song> artistSongs;
	std::copy_if(m_songs.begin(), m_songs.end(), back_inserter(artistSongs), [=](const Song& song) {return song.m_artist == name; });
	return artistSongs;
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