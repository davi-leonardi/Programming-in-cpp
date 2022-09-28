// Workshop 9 - Multi-Threading
// SecureData.cpp
//Name: Davi Leonardi Mathey
//ID: 154979199
//e-mail: dleonardi-mathey@myseneca.ca
//date: Nov 27, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		const size_t tNum = 4;
		size_t sizeArg = 0u;
		size_t eqPartition = nbytes / tNum;
		std::thread t[tNum];

		for (size_t i = 0; i < tNum; i++)
		{
			if (i + 1 < tNum)
				sizeArg = eqPartition;
			else
				sizeArg = nbytes - (eqPartition * i);

			t[i] = std::thread(std::bind(converter, text + (i * eqPartition), key, sizeArg, Cryptor()));
		}

		for (size_t i = 0; i < tNum; i++)
		{
			t[i].join();
		}

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			std::fstream out_bin(file, ios::out | ios::binary);
			if (!out_bin)
				throw std::string("\n***Could not open file***\n");
			
			out_bin.write(text, nbytes);
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::fstream in_bin(file, ios::binary | ios::in);
		if (!in_bin)
		{
			throw std::string("Could not open file");
		}
		else
		{
			///*in_bin.seekg(0, ios::end);
			//nbytes = (int)in_bin.tellg();
			//text = new char[nbytes];
			//in_bin.seekg(ios::beg);
			//int i = 0;
			//in_bin >> noskipws;
			//while (in_bin.good())
			//	in_bin >> text[i++];
			//text[nbytes - 1] = '\0';*/

			char* t = new char[nbytes];
			in_bin.read(t, nbytes);
			delete[] t;
		}

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
