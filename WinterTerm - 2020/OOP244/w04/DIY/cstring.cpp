//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#define _CRT_SECURE_NO_WARNINGS

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

    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;
        int size = 0;
        bool x = false;

        while (src[i] != '\0')
        {
            size++;
            i++;
        }
        if (size < len)
        {
            x = true;
        }

        i = 0;

        while (len > 0)
        {
            des[i] = src[i];
            i++;
            len--;

            if (len == 0 && x == true)
            {
                des[i] = '\0';
            }
        }

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