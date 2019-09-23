//	File:	Tracklist.h
//	Author:	Zhelezov V. D.
//	Date:	23.09.2019
//////////////////////////

#pragma once

#include <cstring>
#include <fstream>
#include <vector>
#include <stack>
#include "Point.h"	//	including struct Point

//	container for tracks
class Tracklist {
private:
	std::stack< std::vector<Point> > tracklist;		//	stack for storing and outputting tracks
	std::vector<Point> current;						//	auxiliary vector for input and output
	std::string filename;							//	input filename
	std::string filedata;							//	input filedata
	std::ifstream filestream;						//	input file
public:
	Tracklist(std::string& fname);		//	constructor
	~Tracklist();						//	destructor

	void fill_list();					//	filling stack using filedata and auxiliary vector
	bool is_empty();					//	checks if stack is empty
	std::vector<Point> get_track();		//	returns vector from the top of the stack
};