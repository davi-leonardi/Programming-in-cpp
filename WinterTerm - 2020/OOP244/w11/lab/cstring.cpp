//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: April 8, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
namespace sdds {

    using namespace std;

    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src)
    {
        int i = 0;

        while (src[i] != '\0')
        {
            des[i] = src[i];
            i++;
        }

        des[i] = '\0';

    }

    int strLen(const char* s)
    {
        int i = 0;

        while (s[i] != '\0')
        {
            i++;
        }

        return i;
    }
    
}