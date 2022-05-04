//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   // TODO: Declare read prototypes
   bool read(char* employee);
   bool read(int& number);
   bool read(double& salary);
}
#endif // !SDDS_FILE_H_
