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
#ifndef SDDS_ShoppingRec_H
#define SDDS_ShoppingRec_H

// Your header file content goes here
namespace sdds {
	const int MAX_TITLE_LENGTH = 50;

	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};




	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif