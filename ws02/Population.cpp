/*
Workshop 2 - Part 2
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 25 - 05 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include "cstring.h" 
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {
	int noOfPopRecords;
	PopRecord* popRecords;

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(PopRecord& popRecord) {
        bool ok = false;
        char code[128] = { '\0' };
        int noOfpeople = 0;
        if (read(code) == true && read(noOfpeople) == true)
        {
            popRecord.postalCode = new char[strLen(code) + 1];
            strCpy(popRecord.postalCode, code);
            popRecord.population = noOfpeople;
            ok = true;
        }
        /* if reading of postal code and population are successful
                keep its address in the postalCode of the PopRecord Reference

                copy the name into the newly allocated memroy

                make sure the "ok" flag is set to true
           end if
        */
        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
    bool load(const char * fileName) {
        bool ok = false;
        int i = 0;
        if (openFile(fileName)) {
            /*
             Set the noOfPopRecords to the number of records in the file.
             dyanamically allocated an array of employees into the global
             PopRecord pointer; "popRecords" to the size of the noOfPopRecords.

             In a loop load the population records from the file into
             the dynamic array.

             If the number of the records does not match the number of reads
                print the message
               "Error: incorrect number of records read; the data is possibly corrupted"
             Otherwise
                set the ok flag to true
             End if

             close the file
             */
            noOfPopRecords = noOfRecords();
            popRecords = nullptr;
            popRecords = new PopRecord[noOfPopRecords];
            for (; i < noOfPopRecords && load(popRecords[i]) == true; i++);
            if (i == noOfPopRecords)
            {
                ok = true;
            }
            else
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << fileName << endl;
        }
        return ok;
    }

    void sort() {
        int i, j;
        PopRecord temp;
        for (i = noOfPopRecords - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (popRecords[j].population > popRecords[j + 1].population) {
                    temp = popRecords[j];
                    popRecords[j] = popRecords[j + 1];
                    popRecords[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Implementation for the display function go here
    void display()
    {
        int i = 0;
        int totalPopulation = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (; i < noOfPopRecords; i++)
        {
            cout << (i + 1) << "- " << popRecords[i].postalCode << ":  " << popRecords[i].population << endl;
            totalPopulation += popRecords[i].population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPopulation << endl;

    }


    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory()
    {
        for (int i = 0; i < noOfPopRecords; i++)
        {
            delete[] popRecords[i].postalCode;
            popRecords[i].postalCode = nullptr;
        }
        delete[] popRecords;
        popRecords = nullptr;
    }

}


