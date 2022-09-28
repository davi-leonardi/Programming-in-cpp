//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

	struct Population {
		char postalCode[3];
		int pop;
	};

#define DATAFILE "PCpopulationsComplete.csv"

	bool load(const char file[]);
	bool load(Population& st);
	void display();
	void sort();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_