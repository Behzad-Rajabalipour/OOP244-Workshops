#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

#include <iostream>
using namespace std;

namespace sdds {
	class MotorVehicle
	{
		char m_license[9] = { '\0' };		// License plate of the motor vehicle (initialized to empty).
		char m_address[64]{ '\0' };		// Address of the motor vehicle (initialized to empty).
		unsigned int m_year{ 0 };		// Year of manufacture (initialized to 0).

	public:
		MotorVehicle() {};				// Default constructor (empty).

		// Constructor with parameters:
		// _license: License plate of the motor vehicle.
		// year_: Year of manufacture.
		// _address: Address (optional) - default value is "Factory".
		MotorVehicle(const char* _license, int year_, const char* _address = "Factory");

		~MotorVehicle() {};				// Destructor (empty). 

		void moveTo(const char* _address);	// Method to change the address of the motor vehicle.

		// Method to write motor vehicle information to an ostream.
		ostream& write(ostream& ostr) const;

		// Method to read motor vehicle information from an istream.
		istream& read(istream& istr);
	};

	// Overloaded << operator to output motor vehicle information.
	ostream& operator<<(ostream& ostr, const MotorVehicle&);

	// Overloaded >> operator to input motor vehicle information.
	istream& operator>>(istream& istr, MotorVehicle&);
}

#endif // !SDDS_MOTORVEHICLE_H
