#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Food.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	
	void Food::set(const char* name, int calories, int when)
	{
		if (name == NULL || calories > 3000 || when < 1 || when > 4)
		{
			setEmpty();
		}
		else
		{	
			cal = 0;	
			timeCode = 0;

			setName(name);	
			cal = calories;
			timeCode = when;
			meal(timeCode);

		}
	}

	void Food::setEmpty()
	{		
		foodName[0] = '\0';
		cal = 0;
		timeCode = 0;
	}

	void Food::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.fill('.');
			cout.width(30);
			cout.setf(ios::left);
			cout << foodName;
			cout << " | ";

			cout.fill(' ');
			cout.width(4);
			cout.unsetf(ios::left);
			cout << cal;
			cout << " | ";

			cout.fill(' ');
			cout.width(10);
			cout << left << mealTime;
			cout << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
		
	}

	bool Food::isValid()const
	{

		if (foodName[0] != '\0' && cal != 0)
		{
			return true;

		}
		else
		{
			return false;
		}
	}

	void Food::setName(const char* name)
	{
		foodName[30] = '\0';

		if (strLen(name) > 30)
		{
			strnCpy(foodName, name, 30);
		}
		else
		{
			strCpy(foodName, name);
		}
	}

	void Food::meal(const int timeCode)
	{		
		mealTime[10] = '\0';

		switch (timeCode)
		{
		case 1:
			strCpy(mealTime, "Breakfast");
			break;
		case 2:
			strCpy(mealTime, "Lunch");
			break;
		case 3:
			strCpy(mealTime, "Dinner");
			break;
		case 4:
			strCpy(mealTime, "Snack");
			break;
		default:
			strCpy(mealTime, "Error");
			break;
		}
	}

	int Food::getCal()const
	{
		return cal;
	}

}