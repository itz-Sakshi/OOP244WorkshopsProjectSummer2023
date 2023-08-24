/*
Workshop 1 - Part 1
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 18 - 05 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#ifndef SDDS_Utils_H
#define SDDS_Utils_H

// Your header file content goes here

#include <cstdio>
#include <iostream>
#include <cstdlib>

namespace sdds {
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}
#endif