/* Citation and Sources...
Final Project Milestone 05
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author:	Davi Leonardi Mathey
ID: 154979199
E-mail: dleonardi-mathey@myseneca.ca
-----------------------------------------------------------
Date        Reason
2021/04/10  Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

using namespace std;
namespace sdds {
	PreTriage::PreTriage(const char* dataFilename) 
		: m_averCovidWait(15)
		, m_averTriageWait(5)
		, m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2)
		, m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		//delete[] m_dataFilename;
		m_dataFilename = nullptr;

		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);

		load();
	}

	PreTriage::~PreTriage()
	{
		int i = 0;

		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: " << m_averCovidWait <<endl;
		cout << "   Triage: " << m_averTriageWait << endl;

		ofstream ofs;

		ofs.open(m_dataFilename);

		if (ofs)
		{
			
			ofs << m_averCovidWait << "," << m_averTriageWait << endl;

			cout << "Saving m_lineup..." << endl;

			for (i = 0; i < m_lineupSize; i++)
			{				
				cout << i + 1 << "- ";
				m_lineup[i]->csvWrite(cout);
				m_lineup[i]->csvWrite(ofs);	
				ofs << endl;
				cout << endl;
			}

			i--;

			while (i > -1)
			{
				removePatientFromLineup(i);		
				i--;
			}
			
		}

		ofs.close();

		delete[] m_dataFilename;
		m_dataFilename = nullptr;

		cout << "done!" << endl;

	}

	const Time PreTriage::getWaitTime(const Patient& p)const
	{
		unsigned int numT = 0, numC = 0;
		bool triage = false, covid = false;
		Time t;

		for (int i = 0; i < m_lineupSize + 1; i++)
		{

			if (m_lineup[i]->type() == 'T')
			{
				numT++;
				triage = true;
				covid = false;
			}
			else if(m_lineup[i]->type() == 'C')
			{
				numC++;
				triage = false;
				covid = true;
			}
		}

		numT--;
		numC--;

		if (triage)
		{
			t = m_averTriageWait * numT;
		}
		else if(covid)
		{
			t = m_averCovidWait * numC;
		}

		return t;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		Time& wait = (p == 'C' ? m_averCovidWait : m_averTriageWait);

		wait = ((getTime() - int(Time(p))) + (int(wait) * (p.number() - 1))) / p.number();
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type)const
	{
		int rtn = -1;
		bool check = false;

		for (int i = 0; i < m_lineupSize && !check; i++)
		{
			if (*m_lineup[i] == type)
			{
				check = true;
				rtn = i;
			}
		}

		return rtn;

	}

	void PreTriage::load()
	{
		cout << "Loading data..." << endl;

		int records = 0;

		ifstream fin;
		fin.open(m_dataFilename);

		if (fin.peek() != ifstream::traits_type::eof())
		{		
			fin >> m_averCovidWait;
			fin.ignore(1000, ',');
			fin >> m_averTriageWait;
			fin.ignore(1000, '\n');

			for (int i = 0; i < maxNoOfPatients && fin; i++)
			{
				Patient* p = nullptr;
				char c = fin.get();
				fin.ignore(1000, ',');

				if (c == 'C')
				{
					p = new CovidPatient();
					p->fileIO(true);
					fin >> *p;
					fin.ignore(1000, '\n');
					p->fileIO(false);
					m_lineup[i] = p;
					m_lineupSize++;
				}
				else if (c == 'T')
				{
					p = new TriagePatient();
					p->fileIO(true);
					fin >> *p;
					p->fileIO(false);
					m_lineup[i] = p;
					m_lineupSize++;
				}

				records = i;
			}
		}

		if (!fin.eof())
		{
			cout << "Warning: number of records exceeded 100" << endl;
			records = 100;
		}

		fin.close();		

		if (!records)
		{
			cout << "No data or bad data file!" << endl << endl;
		}
		else
		{
			cout << records << " Records imported..." << endl << endl;
		}						

	}

	void PreTriage::reg()
	{
		int selection = 0;
		bool flag = false;

		if (m_lineupSize >= maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			if (m_pMenu >> selection == 1)
			{
				m_lineup[m_lineupSize] = new CovidPatient();
			}
			else if (selection == 2)
			{
				m_lineup[m_lineupSize] = new TriagePatient();
			}
			else
			{
				flag = true;
			}

			if (!flag)
			{
				m_lineup[m_lineupSize]->setArrivalTime();
				m_lineup[m_lineupSize]->fileIO(false);
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->read(cin);

				cout << endl;
				cout << "******************************************" << endl;
				m_lineup[m_lineupSize]->write(cout);
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************" << endl << endl;
				m_lineupSize++;
			}
			
		}
	}

	void PreTriage::admit()
	{
		int selection = 0;
		bool flag = false;
		char type;
		int index = 0;

		if (m_pMenu >> selection == 1)
		{
			type = 'C';
		}
		else if (selection == 2)
		{
			type = 'T';
		}
		else
		{
			flag = true;
		}

		if (!flag)
		{
			index = indexOfFirstInLine(type);

			if (index != -1)
			{
				m_lineup[index]->fileIO(false);
				cout << endl;
				cout << "******************************************" << endl;
				cout << "Calling for ";
				m_lineup[index]->write(cout);
				cout << "******************************************" << endl << endl;

				setAverageWaitTime(*m_lineup[index]);
				removePatientFromLineup(index);
			}
		}
	}

	void PreTriage::run(void)
	{
		int selection = 0;

		while (m_appMenu >> selection)
		{
			switch (selection)
			{
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			default:
				break;
			}
		}
	}
		

}

