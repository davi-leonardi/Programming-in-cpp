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

   // TODO: read functions go here    

   bool read(char* name) {

       bool sucess = false;

       if (fscanf(fptr, "%[^\n]\n", name) == 1)
       {
           sucess = true;
       }
        
       return sucess;

   }

   bool read(int& number) {
       
       bool sucess = false;

       if (fscanf(fptr, "%d,", &number) == 1)
       {
           sucess = true;
       }

       return sucess;

   }

   bool read(double& salary) {
    
       bool sucess = false;

       if (fscanf(fptr, "%lf,", &salary) == 1)
       {
           sucess = true;
       }

       return sucess;
   }
   
}