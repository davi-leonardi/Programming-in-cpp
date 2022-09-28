//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
namespace sdds {

	class Mark
	{
		int num;

	public:
		Mark();
		Mark(int number);
		operator int()const;
		operator double()const;
		operator char()const;
		Mark& operator+= (int);
		Mark& operator= (int);
	};

	int operator+= (int&, const Mark&);

}
#endif // !SDDS_MARK_H_