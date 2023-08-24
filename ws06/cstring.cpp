/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 7 - 07 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#include "cstring.h"
namespace sdds {
	void strCpy(char* des, const char* src)
	{
		while (*src != '\0') {
			*des = *src;
			des++;
			src++;
		}
		*des = '\0';
	}

	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int len = 0;
		while (*s != '\0')
		{
			len++;
			s++;
		}
		return len;
	}


	



	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		while (*des != '\0')
		{
			des++;
		}
		while (*src != '\0')
		{
			*des = *src;
			des++;
			src++;
		}
		*des = '\0';
	}
}

