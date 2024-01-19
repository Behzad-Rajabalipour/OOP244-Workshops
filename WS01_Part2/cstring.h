#ifndef SDDS_CSTRING_H_
#define	SDDS_CSTRING_H_


namespace sdds {
	void strCpy(char*, const char*);
	void strnCpy(char*, const char*, int);
	int strCmp(const char*, const char*);
	int strnCmp(const char*, const char*, int);
	int strLen(const char*);
	const char* strStr(const char*, const char*);
	void strCat(char*, const char*);
}



#endif // !SDDS_CSTRING_H_
