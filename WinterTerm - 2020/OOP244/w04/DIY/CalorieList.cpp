#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CalorieList.h"

using namespace std;
namespace sdds {

	void CalorieList::init(int size)
	{		
		noOfItems = size;
		noOfItemsAdd = 0;

		food = nullptr;
		food = new Food[noOfItems];
	}

	bool CalorieList::add(const char* item_name, int calories, int when)
	{
		if (noOfItemsAdd < noOfItems)
		{
			food[noOfItemsAdd].set(item_name, calories, when);			
			noOfItemsAdd++;	
			return true;
		}
		else
		{
			return false;
		}
	}

	void CalorieList::display()const
	{
		int x = noOfItemsAdd;

		while (x < noOfItems)
		{
			food[x].setEmpty();
			x++;
		}
		
		title();

		for (int i = 0; i < noOfItems; i++)
		{
			food[i].display();
		}

		footer();
	}

	void CalorieList::title()const
	{
		cout << "+----------------------------------------------------+" << endl;

		if (isValid())
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}

		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;

	}

	void CalorieList::footer()const
	{
		cout << "+--------------------------------+------+------------+" << endl;

		if (isValid())
		{
			int tCal = totalCal();

				cout << "|    Total Calories for today:";
				cout.fill(' ');
				cout.width(9);
				cout.setf(ios::right);
				cout << tCal;
				cout << " |            |" << endl;
			
		}
		else
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}

		cout << "+----------------------------------------------------+" << endl;
	}

	bool CalorieList::isValid()const
	{

		for (int i = 0; i < noOfItems; i++)
		{
			if (food[i].isValid() == false)
			{
			return false;
			}
		}		
		return true;
	}

	int CalorieList::totalCal()const
	{
		int totalCalories = 0;

		for (int i = 0; i < noOfItems; i++)
		{
			totalCalories += food[i].getCal();
		}

		return totalCalories;
	}

	void CalorieList::deallocate()
	{
		delete[] food;
		food = nullptr;
	}

}