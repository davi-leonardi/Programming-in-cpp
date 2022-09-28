//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 30, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"

namespace sdds {

	template<typename T, typename K>
	// In this function we must have two different templates because we are dealing with two parameters with the same type, and one parameter with a different type to be input by the user.

	bool search(Collection<T>& obj, const T* arr, int size, const K key)
	{		

		bool check = false;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] == key) 
			{
				check = true;
				obj.add(arr[i]);
			}
		}

		return check;
	}

	template<typename T>
	//Differently from the previous function, this only needs one template because the parameters only need input for one generic type, which is the array (const T* arr)

	void listArrayElements(const char* title, const T* arr, int size)
	{
		std::cout << title << std::endl;

		for (int i = 0; i < size; i++)
		{			
			std::cout << i + 1 << ": " << arr[i] << std::endl;					
		}

	}

}
#endif