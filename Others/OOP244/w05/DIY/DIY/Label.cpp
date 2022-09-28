//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#include "Label.h"
#include "cstring.h"
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

namespace sdds
{
	using namespace std;

	Label::Label()
	{
		name = nullptr;
		frame[0] = '\0';
		strCpy(frame, "+-+|+-+|");
	}

	Label::Label(const char* frameArg)
	{
		name = nullptr;
		frame[0] = '\0';
		strCpy(frame, frameArg);
	}

	Label::Label(const char* frameArg, const char* content)
	{
		name = nullptr;
		name = new char[strLen(content) + 1];
		strCpy(name, content);

		frame[0] = '\0';
		strCpy(frame, frameArg);
	}

	Label::~Label()
	{
		delete[] name;
		name = nullptr;
	}

	void Label::readLabel()
	{
		char n[71];

		cout << "> ";
		cin.getline(n, sizeof(n));

		delete[] name;
		name = nullptr;

		name = new char[strLen(n) + 1];
		strCpy(name, n);
	}

	std::ostream& Label::printLabel()const
	{	

		if (name != nullptr)
		{
			cout << frame[0];

			for (int i = 0; i < strLen(name) + 2; i++)
			{
				cout << frame[1];
			}

			cout << frame[2] << endl;
			cout << frame[7];

			for (int i = 0; i < strLen(name) + 2; i++)
			{
				cout << " ";
			}

			cout << frame[3] << endl;
			cout << frame[7] << " ";
			cout << name << " ";
			cout << frame[3] << endl;

			cout << frame[7];

			for (int i = 0; i < strLen(name) + 2; i++)
			{
				cout << " ";
			}

			cout << frame[3] << endl;

			cout << frame[6];

			for (int i = 0; i < strLen(name) + 2; i++)
			{
				cout << frame[5];
			}
			cout << frame[4];

		}

		return cout;
	}
}