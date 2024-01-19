#include <iostream>
#include "Truck.h"

using namespace std;

namespace sdds {

	Truck::Truck(const char* _license, int _year, double _capacity, const char* _address)
		: MotorVehicle(_license, _year) {  // Constructor for Truck class with parameters.
		if (_capacity > 0) m_MaxCapacity = _capacity; // Initialize the maximum cargo capacity.
		if (_address) moveTo(_address); // Call the moveTo method to set the address.
	}

	bool Truck::addCargo(const double cargo) {
		bool flag = false;  // Initialize a flag to indicate success or failure.

		// Check conditions and perform cargo addition.
		(cargo > 0 && m_CurrCapacity < m_MaxCapacity && (m_CurrCapacity += cargo) && (flag = true));

		// Ensure that the current capacity does not exceed the maximum.
		(m_CurrCapacity > m_MaxCapacity) ? (m_CurrCapacity = m_MaxCapacity) : 1;

		return flag;  // Return the flag indicating success or failure.
	}

	bool Truck::unloadCargo() {
		bool flag = false;  // Initialize a flag to indicate success or failure.

		// Check if there is cargo to unload and perform unloading.
		if (m_CurrCapacity > 0) {
			m_CurrCapacity = 0.00;
			flag = true;
		};

		return flag;  // Return the flag indicating success or failure.
	}

	ostream& Truck::write(ostream& os) const {
		MotorVehicle::write(os) << " | " << m_CurrCapacity << "/" << m_MaxCapacity;  // Output truck information.
		return os;
	}

	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);  // Call the read method of the base class.

		cout << "Capacity: ";
		in >> m_MaxCapacity;  // Input maximum cargo capacity and validate.

		while (!in) {
			in.clear();
			in.ignore(32767, '\n');  // Clear input and ignore any remaining characters.
			cout << "Invalid Max Capacity, Retry to enter: ";
			in >> m_MaxCapacity;  // Retry input.
		}

		cout << "Cargo: ";
		in >> m_CurrCapacity;  // Input current cargo capacity and validate.

		while (!in) {
			in.clear();
			in.ignore(32767, '\n');  // Clear input and ignore any remaining characters.
			cout << "Invalid Cargo, Retry to enter: ";
			in >> m_CurrCapacity;  // Retry input.
		}

		return in;
	}

	ostream& operator<<(ostream& ostr, const Truck& ob1) {
		return ob1.write(ostr);  // Output truck information using the write method.
	}

	istream& operator>>(istream& istr, Truck& ob1) {
		return ob1.read(istr);  // Input truck information using the read method.
	}
}
