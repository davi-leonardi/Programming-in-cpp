//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF


#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

using namespace std;
namespace sdds {
	class Food
	{
		char foodName[30];
		int cal;
		int timeCode;
		char mealTime[10];
		void setName(const char* name);
		void meal(const int timeCode);
	public:
		void set(const char* name, int calories, int when);
		void setEmpty();		
		void display()const;
		bool isValid()const;
		int getCal()const;
	};
}
#endif