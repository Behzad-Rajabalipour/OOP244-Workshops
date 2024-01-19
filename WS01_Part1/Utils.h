#ifndef SDDS_UTILS_H
#define	SDDS_UTILS_H

namespace sdds {
	void flushkeys();
	bool ValidYesResponse(char);
	bool yes();
	void readCstr(char [], int);
	int readInt(int, int);

}

#endif 