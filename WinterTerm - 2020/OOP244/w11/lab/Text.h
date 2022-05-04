//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: April 8, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>
namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text&);
      virtual ~Text();
      void operator=(const Text&);
      void read();
      virtual void write(std::ostream&)const;     
   };

   std::ostream& operator<<(std::ostream&, const Text&);
}
#endif // !SDDS_PERSON_H__

