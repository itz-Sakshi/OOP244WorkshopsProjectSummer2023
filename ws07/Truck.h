/***********************************************************************
// OOP244 TRUCK Module
// File	Truck.h
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__

#include "MotorVehicle.h"

namespace sdds
{
	class Truck : public MotorVehicle
	{

		double maxCapacity;
		double currentCapacity;
	public:
		//Truck();
		Truck(const char* plateNumber, int builtYear, double Capacity,const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, const Truck& truck);
	std::istream& operator>>(std::istream& in, Truck& truck);
}
#endif // SDDS_TRUCK_H__
