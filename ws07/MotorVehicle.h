/***********************************************************************
// OOP244 MotorVehicle Module
// File	MotorVehicle.h
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assessments////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__

namespace sdds
{
	class MotorVehicle
	{
		char plateNo[9];
		char VehicleAddress[64];
		int yearBuilt;
	public:
		//MotorVehicle();
		MotorVehicle(const char* plateNumber, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);
	
}
#endif // SDDS_MOTORVEHICLE_H__