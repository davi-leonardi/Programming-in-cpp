//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

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
        // Copies the source character string into the destination upto "len"
        // characters. The destination will be null terminated only if the number
        // of the characters copied is less than "len"
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
        // returns 0 i thare the same
        // return > 0 if s1 > s2
        // return < 0 if s1 < s2
        int strnCmp(const char* s1, const char* s2, int len)
        {

            int i = 0;

            for (i = 0; i < len; i++)
            {
                if (s1[i] != s2[i])
                {
                    return 1;
                }
            }

            return 0;

        }

        // returns the lenght of the C-string in characters

        int strLen(const char* s)
        {
            int i = 0;

            while (s[i] != '\0')
            {
                i++;
            }

            return i;
        }

        // returns the address of first occurance of "str2" in "str1"
        // returns nullptr if no match is found
        const char* strStr(const char* str1, const char* str2)
        {
            int a = 0, b = 0, c = 0;

            while (str1[a] != '\0')
            {
                c = a;

                while (str2[b] != '\0')
                {
                    if (str1[c] != str2[b])
                    {
                        break;
                    }

                    b++;
                    c++;
                }

                if (str2[b] == '\0')
                {
                    return (char*)str1 + a;
                }
                else
                {
                    b = 0;
                    a++;
                }
            }

            return nullptr;
        }

        // Concantinates "src" C-string to the end of "des"
        void strCat(char* des, const char* src)
        {
            int i = 0, x = 0;

            while (des[i] != '\0')
            {
                i++;
            }

            while (src[x] != '\0')
            {
                des[i] = src[x];
                i++;
                x++;
            }

            des[i] = '\0';
        }

}