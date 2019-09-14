//	File:	group.h
//	Author:	Zhelezov V. D.
//	Date:	14.09.2019
//////////////////////////
#pragma once

#include "student.h"

//	objects of this class are nodelists
class group {
private:
	student* head;			//	head of nodelist
	unsigned day;			//	count of days (files incuding attendance)
	bool names_are_filled;	//	variable for chek if students names are identified either not
	std::ofstream outfile;	//	file to save results
public:
	group(): head(NULL), day(0), names_are_filled(false), outfile("csv_out/attendance_group_M3O-221B-18.csv")
	{};								//	constructor
	~group();						//	destructor

	void add(std::string name);				//	identifies student's name. is used in a loop in method "fill"
	void show();							//	prints results in console
	void fill(std::string first_file);		//	identifies students names from text of the first file
	void note(std::string current_file);	//	accounts students attendance from current file (day)
	bool is_filled()						//	checks if student names are identified or not
	{ return names_are_filled; };

	void save();							//	saves results into output file
};