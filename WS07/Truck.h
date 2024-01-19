#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"  // Include the MotorVehicle header.

using namespace std;

namespace sdds {
	class Truck : public MotorVehicle { // Define a Truck class derived from MotorVehicle.
		double m_MaxCapacity = 0.00;    // Maximum cargo capacity of the truck.
		double m_CurrCapacity{ 0.00 }; // Current cargo capacity of the truck.

	public:
		Truck() {}; // Default constructor (empty).

		// Constructor with parameters:
		// _license: License plate of the truck.
		// _year: Year of manufacture.
		// _capacity: Maximum cargo capacity of the truck.
		// _address: Address (optional) - default value is nullptr.
		Truck(const char* _license, int _year, double _capacity, const char* _address = nullptr);

		~Truck() {}; // Destructor (empty).

		bool addCargo(const double); // Method to add cargo to the truck.
		bool unloadCargo();          // Method to unload cargo from the truck.

		ostream& write(ostream&) const; // Method to write truck information to an ostream.
		istream& read(istream&);       // Method to read truck information from an istream.
	};

	// Overloaded << operator to output truck information.
	ostream& operator<<(ostream&, const Truck&);

	// Overloaded >> operator to input truck information.
	istream& operator>>(istream&, Truck&);
}

#endif // !SDDS_TRUCK_H
