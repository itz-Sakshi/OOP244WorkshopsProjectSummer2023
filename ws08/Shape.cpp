/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds
{
	

	std::ostream& operator<<(std::ostream& os, const Shape& shape)
	{
		shape.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, Shape& shape)
	{
		shape.getSpecs(in);
		return in;
	}
	Shape::~Shape() = default;
}
