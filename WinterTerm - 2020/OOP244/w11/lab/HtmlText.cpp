//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF
//Date: April 8, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <cstring>
#include "HtmlText.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename)
	{

		m_title = nullptr;

		if (title)
		{
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}

	}

	HtmlText::HtmlText(const HtmlText& obj) : Text(obj)
	{
		m_title = new char[strLen(obj.m_title) + 1];
		strCpy(m_title, obj.m_title);
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	void HtmlText::operator=(HtmlText& obj)
	{
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}
		
		m_title = new char[strLen(obj.m_title) + 1];
		strCpy(m_title, obj.m_title);

		Text::operator=(obj);
	}


	void HtmlText::write(ostream& os)const
	{

		int i = 0;
		char c = 0;
		const HtmlText& T = *this;
		bool ms = false;

		os << "<html><head><title>";
		
		if (m_title)
		{
			os << m_title;
		}
		else
		{
			os << "No Title";
		}
		
		os << "</title></head>\n<body>\n";

		if (m_title)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}	

		while (T[i])
		{	
			c = T[i];

			switch (c) {
			case ' ':
				if (ms)
				{
					os << "&nbsp;";
				}
				else
				{
					ms = true;
					os << ' ';
				}
				break;
			case '<':
				os << "&lt;";
				ms = false;
				break;
			case '>':
				os << "&gt;";
				ms = false;
				break;
			case '\n':
				os << "<br />\n";
				ms = false;
				break;
			default:
				ms = false;
				os << c;
				break;
			}

			i++;
		}
		
		os << "</body>\n</html>";
	}

}