/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Streamable& S) {
		if (S) {
			return S.write(os);
		}
		return os;
	}
	std::istream& operator>>(std::istream& is, Streamable& S) {
		return S.read(is);
	}
}