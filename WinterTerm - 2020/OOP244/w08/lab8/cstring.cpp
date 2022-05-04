//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: March 17, 2021

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

    // Compares two C-strings 
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2)
    {
        int i = 0;

        while (s1[i] != '\0' || s2[i] != '\0')
        {

            if (s1[i] != s2[i])
            {
                return 1;
            }
            i++;
        }

        return 0;

    }
}
