// Name: Davi Leonardi Mathey
// Seneca Student ID: 154979199
// Seneca email: dleonardi-mathey@myseneca.ca
// Date of completion: Dec 2, 2021

// I confirm that I am the only author of this file and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <vector>
#include "Workstation.h"

namespace sdds {

	class LineManager {
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};

}

#endif
