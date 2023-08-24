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
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
	MotorVehicle::MotorVehicle(const char* plateNumber, int year)
	{
		strCpy(plateNo, plateNumber);
		strCpy(VehicleAddress, "Factory");
		yearBuilt = year;
	}
	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(VehicleAddress, address) != 0) 
		{
			cout << "|";
			cout << right;
			cout.width(8);
			cout << plateNo << "| |";
			cout.width(20);
			cout << VehicleAddress << " ---> ";
			cout << left;
			cout.width(20);
			cout << address << "|" << endl;
			strCpy(VehicleAddress, address);
		}
	}
	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		os << "| " << yearBuilt << " | " << plateNo << " | " << VehicleAddress;
		return os;
	}
	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> yearBuilt;
		cout << "License plate: ";
		in.ignore();
		in.getline(plateNo, 9);
        cout << "Current location: ";
		in.getline(VehicleAddress, 64);
		return in;
	}

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle)
	{
		return vehicle.write(os);
	}
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle)
	{
		return vehicle.read(in);
	}
}