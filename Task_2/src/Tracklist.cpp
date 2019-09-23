//	File:	Tracklist.h
//	Author:	Zhelezov V. D.
//	Date:	24.09.2019
//////////////////////////

#include <iostream>
#include "Tracklist.h"

using namespace std;

//	constructor
Tracklist::Tracklist(string& fname): filename(fname) {
	filestream.open(filename);

	if(!filestream.is_open())
		return;

	string temp((istreambuf_iterator<char>(filestream)), istreambuf_iterator<char>());
	filedata = temp;
}

//	destructor
Tracklist::~Tracklist() {
	if(filestream.is_open())
		filestream.close();
}

//	filling stack using filedata and auxiliary vector
void Tracklist::fill_list() {
	int i;						//	iterator
	int temp_coord = 0;			//	changable coordinate (x or y)
	bool is_positive = true;	//	is sign of value of x or y positive either negative
	bool is_xCoord = true;		//	is current number a value of abscissa either ordinate
	Point temp_point;			//	auxiliary point-variable

//	main loop: reading sign by sign filedata and filling stack with track-vectors
	for(i = 0; i < filedata.size(); i++) {

	//	reading and interpretating a number
		while((filedata[i] <= '9' && filedata[i] >= '0') || filedata[i] == '-') {
			if(filedata[i] == '-') {
				is_positive = false;
				i++;
			}
			else {
				temp_coord = temp_coord * 10 + filedata[i] - '0';
				i++;
			}
		}

	//	initialization of the current point coordinates
		if(is_xCoord) {
			if(is_positive)
				temp_point.x = temp_coord;
			else {
				temp_point.x = -temp_coord;
				is_positive = true;
			}

			is_xCoord = false;
		}
		else {
			if(is_positive)
				temp_point.y = temp_coord;
			else {
				temp_point.y = -temp_coord;
				is_positive = true;
			}

			is_xCoord = true;

		//	filling the auxiliary vector with the current point
			current.push_back(temp_point);
		}

	//	reset changable coordinate
		temp_coord = 0;

	//	cases like ";;;;;;;;;" in csv file
		while(filedata[i] == ';' && 
			(filedata[i+1] == ';' || filedata[i+1] == '\n' || filedata[i+1] == '\0' || filedata[i+1] == '\r'))
			i++;

	//	skip the f***ing '\r'
		if(filedata[i] == '\r')
			i++;

	//	in the end of string adding the current track to the stack and reseting the vector
		if(filedata[i] == '\n' || filedata[i] == '\0') {
			tracklist.push(current);
			current.clear();
		}
	}
}

//	checks if stack is empty
bool Tracklist::is_empty() {
	return tracklist.empty();
}

//	returns vector from the top of the stack
vector<Point> Tracklist::get_track() {
	//	check if stack is empty
	if(tracklist.empty()) {
		cout << "Tracklist is empty!" << endl;
		exit(0);
	}
	
	current = tracklist.top();
	tracklist.pop();
	return current;
}