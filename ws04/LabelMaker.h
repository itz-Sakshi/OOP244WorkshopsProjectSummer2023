/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 11 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_LabelMaker_H
#define SDDS_LabelMaker_H


#include <iostream>
#include "Label.h"

namespace sdds
{
	class LabelMaker
	{
	private:
		int numOfLabels;
		Label* labels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}



#endif // !SDDS_LABELMAKER_H