//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* PC) {

       bool sucess = false;

       if (fscanf(fptr, "%3s", PC) == 1) 
       {
           sucess = true;
       }

       return sucess;

   }

   bool read(int& pop) {

       bool sucess = false;

       if (fscanf(fptr, ",%d", &pop) == 1)
       {
           sucess = true;
       }

       return sucess;

   }

}