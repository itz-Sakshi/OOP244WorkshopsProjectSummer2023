/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 03 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "cstring.h"
namespace sdds {
	void strnCpy(char* des, const char* src, int len)
	{
		{
			int i = 0;
			while (*src != '\0' && i < len)
			{
				*des = *src;
				des++;
				src++;
				i++;
			}
			if (i < len)
			{
				*des = '\0';
			}
		}
	}

}