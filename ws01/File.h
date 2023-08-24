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
#ifndef SDDS_File_H
#define SDDS_File_H

// Your header file content goes here
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "ShoppingRec.h"

namespace sdds {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif