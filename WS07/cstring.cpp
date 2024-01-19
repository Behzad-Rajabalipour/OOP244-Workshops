#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include <cstring>

namespace sdds {
	bool strCmp(const char* name1,const char* name2) {
		if (name1 && name2)
			return strcmp(name1, name2);
		return true;
	}

	int strLen(const char* const name1) {							// both pointer and data are not modifiable
		return strlen(name1);
	}

	void strCpy(char* name1, const char* name2) {
		if (name1 && name2)
			strcpy(name1, name2);
	}
}