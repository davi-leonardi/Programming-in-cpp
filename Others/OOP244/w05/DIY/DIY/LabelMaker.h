//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#pragma once
#include "Label.h"

#ifndef SDDS_LABELMAKER_H_
#define SDDS_LABELMAKER_H_

namespace sdds
{
	class LabelMaker
	{
		Label* labels;
		int noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif