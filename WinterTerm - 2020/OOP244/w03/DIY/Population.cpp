//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {

    int noOfPC;
    Population* population;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPC - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].pop > population[j + 1].pop) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }

    bool load(const char file[]) {
        bool ok = false;
        int i = 0;
        bool checker = true;

        if (openFile(DATAFILE)) {

            noOfPC = noOfRecords();

            population = new Population[noOfPC];

            while (i < noOfPC && checker == true)
            {
                checker = load(population[i]);
                i++;
            }

            if (checker == false)
            {
                cout << i << endl;
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true;
            }

            closeFile();

        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    bool load(Population& st) {

        bool ok = false;

        if (read(st.postalCode) && read(st.pop))
        {
            ok = true;
        }

        return ok;
    }

    void display()
    {
        int sum = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        
        sort();

        for (int i = 0; i < noOfPC; i++)
        {
            cout << i + 1 << "- " << population[i].postalCode << ":  " << population[i].pop << endl;
            sum += population[i].pop;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << sum << endl;
    }

    void deallocateMemory()
    {
        population = nullptr;
        delete[] population;
    }

}