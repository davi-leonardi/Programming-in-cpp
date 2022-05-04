#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }


   TextFile::TextFile(unsigned pageSize)
   {
       setEmpty();
       m_pageSize = pageSize;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize)
   {
       setEmpty();
       m_pageSize = pageSize;

       if (filename[0] != '\0')
       {           
           setFilename(filename);
           cout << "deu bom";
           setNoOfLines();
           cout << "deu bom";
           loadText();
       }

   }

   TextFile::TextFile(const TextFile& tf)
   {
       m_pageSize = tf.m_pageSize;
       m_textLines = nullptr;
       m_filename = nullptr;
       m_noOfLines = 0;
        
       if (tf)
       {
           setFilename(tf.m_filename, true);
           saveAs(tf.m_filename);
           setNoOfLines();
           loadText();
       }

   }

   void TextFile::setFilename(const char* fname, bool isCopy)
   {

       delete[] m_filename;
       m_filename = nullptr;
       
       if (!isCopy)
       {        
           m_filename = new char[strLen(fname) + 1];
           strCpy(m_filename, fname);
           
           
       }
       else
       {
           m_filename = new char[strLen(fname) + 3];
           strCpy(m_filename, "C_");
           strCat(m_filename, fname);
       }
       
   }

   void TextFile::setEmpty()
   {
       delete[] m_textLines;
       m_textLines = nullptr;

       delete[] m_filename;
       m_filename = nullptr;

       m_noOfLines = 0;
   }

   void TextFile::setNoOfLines()
   {
       ifstream file(m_filename);

       while (file)
       {
           m_noOfLines += (file.get() == '\n');
       }

       if (m_noOfLines == 0)
       {
           setEmpty();
       }

       m_noOfLines++;      
   }

   void TextFile::loadText()
   {
       int i = 0;
       string lines;

       if (m_filename[0] != '\0')
       {
           ifstream file(m_filename);

           delete[] m_textLines;
           m_textLines = nullptr;

           m_textLines = new Line[m_noOfLines];

           while (getline(file, lines))
           {
               m_textLines[i++] = lines.c_str();
           }

           m_noOfLines = i;

       }
   }

   void TextFile::saveAs(const char* fileName)const
   {
       ofstream file(fileName);

       int nLines = m_noOfLines;

       for (int i = 0; i < nLines; i++)
       {
           file << m_textLines[i] << endl;
       }

   }

   TextFile::operator bool()const
   {
       bool rtn = false;

       if (m_filename[0] != '\0') rtn = true;

       return rtn;
   }

   TextFile& TextFile::operator=(const TextFile& tf)
   {
       if (*this && tf)
       {
           delete[] m_textLines;
           m_textLines = nullptr;

           saveAs(tf.m_filename);
           setNoOfLines();
           loadText();
       }

       return *this;
   }

   TextFile::~TextFile()
   {
       delete[] m_textLines;
       m_textLines = nullptr;

       delete[] m_filename;
       m_filename = nullptr;
   }
   
   unsigned TextFile::lines()const
   {
       return m_noOfLines;
   }

   ostream& TextFile::view(ostream& ost)const
   {
       
       if (m_filename[0] != '\0')
       {
           int len = 0;
           int nLines = m_noOfLines;

           ost << m_filename << endl;
           len = strLen(m_filename);

           for (int i = 0; i < len; i++) ost << '=';

           ost << endl;

           for (int x = 0; x < nLines; x++)
           {
               if ((x + 1) % m_pageSize == 0)
               {
                   ost << "Hit ENTER to Continue...";
                   cin.ignore(1000, '\n');
               }
           }
       }

       return ost;
   }

   istream& TextFile::getFile(istream& istr)
   {

       istr >> m_filename;
       setNoOfLines();
       loadText();

       return istr;
   }

   const char* TextFile::name()const
   {
       return m_filename;
   }

   const char* TextFile::operator[](unsigned index)const
   {
       const char* line = nullptr;

       if (*this)
       {
           line = m_textLines[index % m_noOfLines];
       }

       return line;
   }

   ostream& operator<<(ostream& ostr, const TextFile& text)
   {
       return text.view(ostr);
   }

   istream& operator>>(std::istream& istr, TextFile& text)
   {
       return text.getFile(istr);
   }

}