//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#include "LabelMaker.h"
#include "Label.h"
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

namespace sdds
{
	using namespace std;

	LabelMaker::LabelMaker(int noOfLabels)
	{
		labels = nullptr;

		labels = new Label[noOfLabels];
		this->noOfLabels = noOfLabels;
	}

	void LabelMaker::readLabels()
	{
		cout << "Enter " << noOfLabels << " labels:" << endl;

		for (int i = 0; i < noOfLabels; i++)
		{
			cout << "Enter label number " << i + 1 << endl;
			labels[i].readLabel();
		}

	}

	void LabelMaker::printLabels()
	{
		for (int i = 0; i < noOfLabels; i++)
		{
			labels[i].printLabel();
			cout << endl;
		}
	}

	LabelMaker::~LabelMaker()
	{
		delete[] labels;
		labels = nullptr;
	}

}