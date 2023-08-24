#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Utils.h"
using namespace std;

namespace sdds
{

	// Copies the source character string into the destination
	void strCpy(char* des, const char* src)
	{
		while (*src != '\0') {
			*des = *src;
			des++;
			src++;
		}
		*des = '\0';
	}


	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
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


	// Compares two C-strings 
	// returns 0 i they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s
	int strCmp(const char* s1, const char* s2)
	{
		while (*s1 != '\0' && (*s1 == *s2)) {
			s1++;
			s2++;
		}
		return *(char*)s1 - *(char*)s2;
	}



	// returns 0 i they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		int i = 0;
		while (*s1 != '\0' && (*s1 == *s2) && i < len)
		{
			s1++;
			s2++;
			i++;
		}
		if (i == len)
		{
			return 0;
		}
		return *(char*)s1 - *(char*)s2;
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


	// returns the address of first occurence of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		while (*str1)
		{
			const char* startStr = str1;
			const char* matchStr = str2;
			while (*str1 != '\0' && *matchStr != '\0' && (*str1 == *matchStr))
			{
				str1++;
				matchStr++;
			}
			if (*matchStr == '\0')
				return startStr;
			str1 = startStr + 1;
		}
		return nullptr;
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
