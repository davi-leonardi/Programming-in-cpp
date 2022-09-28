/* Citation and Sources...
Final Project Milestone 03
Module: Utils
Filename: Utils.cpp
Version 1.0
Author:	Davi Leonardi Mathey
ID: 154979199
E-mail: dleonardi-mathey@myseneca.ca
-----------------------------------------------------------
Date        Reason
2021/03/27  Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int getInt(const char* prompt)
   {
       return getInt(-1, -2, std::cin, prompt);
   }

   int getInt(int min, int max, std::istream& istr, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       string input;

       bool pass = false;
       bool notInt = false;
       bool hasRange = false;

       if (min != -1 && max != -2)
       {
           hasRange = true;
       }

       if (prompt != nullptr)
       {
           cout << prompt;
       }

       do
       {
           getline(istr, input);

           if (isdigit(input[0]) || input[0] == '-' || input[0] == '+')
           {
               for (unsigned int i = 1; i < input.length(); i++)
               {
                   if (!isdigit(input[i]))
                   {
                       notInt = true;
                   }
               }

               if (notInt)
               {
                   notInt = false;
                   input.clear();
                   cout << "Enter only an integer, try again: ";
               }
               else
               {
                   pass = true;
               }

           }
           else
           {
               input.clear();
               cout << "Bad integer value, try again: ";
           }

           if (hasRange && pass && (stoi(input) > max || stoi(input) < min))
           {
               pass = false;
               
               if (errorMessage != nullptr)
               {
                   cout << errorMessage;
               }

               if (showRangeAtError == true)
               {
                   cout << "[" << min << " <= value <= " << max << "]: ";
               }

           }

       } while (!pass);

       return stoi(input);
   }

   char* getcstr(const char* prompt, istream& istr, char delimiter)
   {
       string str;
       char* input = nullptr;      

       if (prompt != nullptr)
       {
           cout << prompt;
       }

       getline(istr, str, delimiter);
       
       input = new char[str.length() + 1];
       strcpy(input, str.c_str());

       return input;
   }
   
}