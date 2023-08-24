/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	const char* LblShape::label() const
	{
		return m_label;
	}
	void LblShape::getSpecs(std::istream& in)
	{
		char buffer[256];
		in.getline(buffer, 256, ',');
		if (buffer != nullptr)
		{
			delete[] m_label;
			m_label = new char[std::strlen(buffer) + 1];
			std::strcpy(m_label, buffer);
		}
		
	}
	LblShape::LblShape()
	{
		if (m_label != nullptr)
		{
			m_label = nullptr;
		}		
	}
	LblShape::LblShape(const char* labelStr)
	{
		if (labelStr != nullptr)
		{
			m_label = new char[std::strlen(labelStr) + 1];
		    std::strcpy(m_label, labelStr);
		}
		
	}
	LblShape::~LblShape()
	{
		delete[] m_label;
	}
	
}