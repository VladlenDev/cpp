//	File:	textfile.h
//	Author:	Zhelezov V. D.
//	Date:	14.09.2019
//////////////////////////
#pragma once

#include <fstream>
#include <streambuf>
#include <cstring>

//	simple class for easy reading and transforming textfiles
class textfile {
private:
	std::string filename, filedata;		//	containing filename and filedata (text) respectively
	std::ifstream filestream;			//	input textfile
public:
	textfile()									//	constructor
	{ };
	~textfile()									//	destructor
	{ if(filestream.is_open()) filestream.close(); };

	void initialize(const std::string& fname);	//	initializes file using filename, writes text from file to string "filedata"
	std::string getdata()						//	returns text from string "filedata" to calling environment
	{ return filedata; };
};
