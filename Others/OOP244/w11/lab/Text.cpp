//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: April 8, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"
#include "HtmlText.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    const char& Text::operator[](int index)const
    {
        return m_content[index];
    }

    Text::Text(const Text& obj)
    {
        m_filename = new char[strLen(obj.m_filename) + 1];
        strCpy(m_filename, obj.m_filename);

        m_content = new char[strLen(obj.m_content) + 1];
        strCpy(m_content, obj.m_content);
    }

    Text::~Text()
    {
        delete[] m_filename;
        m_filename = nullptr;

        delete[] m_content;
        m_content = nullptr;
    }

    void Text::operator=(const Text& obj)
    {

        if (m_filename)
        {
            delete[] m_filename;
            m_filename = nullptr;
        }

        m_filename = new char[strLen(obj.m_filename) + 1];
        strCpy(m_filename, obj.m_filename);
        
        
        if (m_content)
        {
            delete[] m_content;
            m_content = nullptr;
        }

        m_content = new char[strLen(obj.m_content) + 1];
        strCpy(m_content, obj.m_content);
        
    }

    void Text::read()
    {       
        m_content = new char[getFileLength() + 1];

        string str;

        ifstream fin(m_filename);
        while (fin) {
            getline(fin, str, '\0');
        }
        fin.close();

        strCpy(m_content, str.c_str());

    }

    void Text::write(ostream& os)const
    {  
        if (m_content)
        {
            os << m_content;
        }
    }


    ostream& operator<<(ostream& os, const Text& obj){   
        obj.write(os);
        return os;
    }

    Text::Text(const char* filename)
    {  

        m_filename = nullptr;

        m_content = nullptr;
        
        if (filename)
        {            
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read();
        }
       
    }

}