#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
   // TODO: Declare read prototypes
	bool read(int&);
	bool read(double&);
	bool read(char*);
	

}
#endif // !SDDS_FILE_H_
