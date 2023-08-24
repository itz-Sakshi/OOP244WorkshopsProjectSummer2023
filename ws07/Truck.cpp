/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "Truck.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
	Truck::Truck(const char* plateNumber, int builtYear, double Capacity,const char* address) 
		:MotorVehicle(plateNumber, builtYear)
	{
		maxCapacity = Capacity;
		currentCapacity = 0;
		moveTo(address);
	}
	bool Truck::addCargo(double cargo)
	{
		bool result = false;

		if (cargo > 0 && (currentCapacity != maxCapacity)) {
			currentCapacity += cargo;
			result = true;
			if (currentCapacity > maxCapacity) currentCapacity = maxCapacity;
		}

		return result;
	}
	bool Truck::unloadCargo()
	{
		bool result = false;
		if (currentCapacity > 0) {
			currentCapacity = 0;
			result = true;
		}
		return result;
	}
	std::ostream& Truck::write(std::ostream& os) const
	{
		MotorVehicle::write(os);
		os << " | ";
		cout << currentCapacity << "/" << maxCapacity;
		return os;
	}
	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		std::cout << "Capacity: ";
		in >> maxCapacity;
		std::cout << "Cargo: ";
		in >> currentCapacity;
		return in;
	}

    std::ostream& operator<<(std::ostream& os, const Truck& truck)
	{
		return truck.write(os);
	}
    std::istream& operator>>(std::istream& in, Truck& truck)
	{
		return truck.read(in);
	}
}
