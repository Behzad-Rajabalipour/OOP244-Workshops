#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds {
	MotorVehicle::MotorVehicle(const char* _license, int year_, const char* _address) {
		if (_license) strCpy(m_license, _license);  // Copy the license plate if provided.
		m_year = year_;
		strCpy(m_address, _address);  // Copy the address if provided.
	}

	void MotorVehicle::moveTo(const char* address_) {
		if (strCmp(m_address, address_) != 0) {  // Check if the addresses are different.
			cout << "|";
			cout.width(8);  // Set the width for license plate output.
			cout << m_license << "| |";
			cout.width(20);  // Set the width for address output.
			cout << m_address << " ---> ";
			cout.width(20);  // Set the width for the new address output.
			cout << left << address_ << right << "|" << endl;  // Output the address change.

			strCpy(m_address, address_);  // Update the address.
		}
	}

	ostream& MotorVehicle::write(ostream& os) const {
		os << "|";
		os.width(5);  // Set the width for year output.
		os << m_year << " | " << m_license << " | " << m_address;  // Output vehicle information.
		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		in >> m_year;

		while (!in) {
			in.clear();
			in.ignore(32767, '\n');  // Clear input and ignore any remaining characters.
			cout << "Invalid year, Retry to enter: ";
			in >> m_year;
		}

		cout << "License plate: ";
		in >> m_license;

		cout << "Current location: ";
		in >> m_address;

		while (m_address[0] < 65 || m_address[0] > 122) {
			in.clear();
			in.ignore(32767, '\n');  // Clear input and ignore any remaining characters.
			cout << "Invalid location, Retry to enter: ";
			in >> m_address;
		}
		return in;
	}

	ostream& operator<<(ostream& ostr, const MotorVehicle& ob1) {
		return ob1.write(ostr);  // Output vehicle information using the write method.
	}

	istream& operator>>(istream& istr, MotorVehicle& ob1) {
		return ob1.read(istr);  // Input vehicle information using the read method.
	}
}
