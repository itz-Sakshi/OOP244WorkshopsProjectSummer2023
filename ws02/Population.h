/*
Workshop 2 - Part 2
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 25 - 05 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define POSTAL_CODE_LENGTH 3
namespace sdds {
	struct PopRecord
	{
		char* postalCode;
        int population;
	};
    // loads a PopRecord structue with its values from the file
    bool load(PopRecord & popRecord);

    // allocates the dyanmic array of PopRecords and loads all the file
    // recoreds into the array
    bool load(const char *fileName);


    // TODO: Declare the prototype for the display function that 
    // displays all the population records on the screen
    void display();

    // TODO: Declare the prototype for the deallocateMemory function that
    // first will deallocate all the names in the postal code elements
    // then it will deallocate the Population records array 
    void deallocateMemory();



}
#endif // SDDS_POPULATION_H_