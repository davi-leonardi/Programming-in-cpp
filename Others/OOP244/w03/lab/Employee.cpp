//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& st) {

      bool ok = false;
      char name[128];
      int len = 0;


      if (read(st.m_empNo) && read(st.m_salary) && read(name))
      {
          len = strLen(name);
          
          st.m_name = new char[len + 1];
        
          strCpy(st.m_name, name);

          ok = true;
      }

      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      bool checker = true;
      if (openFile(DATAFILE)) {
         
          noOfEmployees = noOfRecords();

          employees = new Employee[noOfEmployees];

          while (i < noOfEmployees && checker == true)
          {
              checker = load(employees[i]);
              i++;
          }

          if (checker == false)
          {
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
          }
          else
          {
              ok = true;
          }

          closeFile();

      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }   
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& st)
   {
       cout << st.m_empNo << ":" << st.m_name << st.m_salary << endl;
   }

   void display()
   {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;

       sort();

       for (int i = 0; i < noOfEmployees; i++)
       {
           cout << i + 1 << "- " << employees[i].m_empNo << ": " << employees[i].m_name << ", " << employees[i].m_salary << endl;
       }

   }
   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory()
   {            
       employees = nullptr;
       delete[] employees;
   }


}