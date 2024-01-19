#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include "File.h"
#include <cstdio>
#include <iostream>
#include "iomanip"

namespace sdds {
	struct Population {
		char* postal_code;
		int population;
	};
	bool load(const char[]);
	void display();
	void deallocateMemory();
	void sort();

}
#endif // SDDS_POPULATION_H_