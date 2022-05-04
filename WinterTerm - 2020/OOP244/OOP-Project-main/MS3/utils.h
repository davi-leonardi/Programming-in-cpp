/* Citation and Sources...
Final Project Milestone 03
Module: Utils
Filename: Utils.h
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

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   extern bool debug;

   int getTime(); 

   int getInt(const char* prompt = nullptr);

   int getInt(
       int min,   
       int max,
       std::istream& istr = std::cin,
       const char* prompt = nullptr,  
       const char* errorMessage = nullptr, 
       bool showRangeAtError = true    
   );

   char* getcstr(
       const char* prompt = nullptr,   
       std::istream& istr = std::cin,  
       char delimiter = '\n'    
   );

}
#endif // !SDDS_UTILS_H_

