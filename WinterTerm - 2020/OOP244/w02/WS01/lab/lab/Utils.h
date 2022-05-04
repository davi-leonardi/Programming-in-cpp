//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#pragma once
#ifndef NAMESPACE_UTILS_H // replace with relevant names
#define NAMESPACE_UTILS_H
namespace sdds {
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}
#endif