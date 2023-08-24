/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 11 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Label.h"
using namespace std;
namespace sdds {
	Label::Label()
	{
		strCpy(frameString, "+-+|+-+|");
		textString = nullptr;
	}
	Label::Label(const char* frameArg)
	{
		strCpy(frameString, frameArg);
		textString = nullptr;
	}
	Label::Label(const char* frameArg, const char* content)
	{
		strCpy(frameString, frameArg);
		int strLength = strLen(content);

		if (strLength < 71)
		{
			textString = new char[strLength + 1];
			strCpy(textString, content);
		}
	}
	Label::~Label()
	{
		if (textString != nullptr && textString[0] != '\0')
		{
			delete[] textString;
			textString = nullptr;
		}
	}
	void Label::readLabel()
	{
		char input[71];
		cout << "> ";
		cin.get(input, 71);
		cin.ignore(10000, '\n');
		textString = new char[strLen(input) + 1];
		strCpy(textString, input);
	}
	std::ostream& Label::printLabel()const
	{
		if (textString) {
			int len = strLen(textString);
			int i;
			cout << frameString[0];
			for (i = 0; i < len + 2; i++) {
				cout << frameString[1];
			}
			cout << frameString[2] << endl;
			cout << frameString[7];
			cout.fill(' ');
			cout.width(len + 3);
			cout << frameString[3] << endl;
			cout << frameString[7];
			cout << " " << textString << " " << frameString[3] << endl;
			cout << frameString[7];
			cout.fill(' ');
			cout.width(len + 3);
			cout << frameString[3] << endl;
			cout << frameString[6];
			for (i = 0; i < len + 2; i++) {
				cout << frameString[5];
			}
			cout << frameString[4];
		}
		return cout;
	}
}