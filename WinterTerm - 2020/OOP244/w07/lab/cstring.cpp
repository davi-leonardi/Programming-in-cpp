#include "cstring.h"
namespace sdds {

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