/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 11 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "LabelMaker.h"
using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels)
	{
		numOfLabels = noOfLabels;
		labels = new Label[numOfLabels];
	}
	void LabelMaker::readLabels()
	{
		if (numOfLabels > 0) {
			cout << "Enter " << numOfLabels << " labels:" << endl;
			for (int i = 0; i < numOfLabels; i++) {
				cout << "Enter label number " << i + 1 << endl;
				labels[i].readLabel();
			}
		}
	}
	void LabelMaker::printLabels()
	{
		for (int i = 0; i < numOfLabels; ++i)
		{
			labels[i].printLabel();
			cout << endl;
		}
	}
	LabelMaker::~LabelMaker()
	{
		delete[] labels;
		labels = nullptr;
	}
}