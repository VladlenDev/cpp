//	File:	student.h
//	Author:	Zhelezov V. D.
//	Date:	14.09.2019
//////////////////////////
#pragma once

#include <iostream>
#include <iomanip>
#include "textfile.h"

//	objects of this class are nodes
class student {
private:
	std::string name;			//	name of student essentially is personal identificator
	static const unsigned DAYS = 10;	//	is used just for array below
	bool attendance[DAYS];		//	student attendance accounting
	student *next;				//	connection in nodelist
public:
	void operator<<(student* operand)						//	adds new branch to the list
	{ next = operand; };

	void regist(std::string nm)								//	initializes student's name
	{ name = nm; };

	std::string getname()									//	returnes student's name to calling environment
	{ return name; };

	student* get_next()										//	goes next through the list
	{ return next; };

	void note(unsigned day, bool attend)					//	accounts student's attendance
	{ if(day < 20) attendance[day] = attend; };

	void display(unsigned days) {							//	prints information about student in console
		std::cout << std::setw(20) << name << '\t';

		for(int i = 0; i < days; i++)
			std::cout << ' ' << attendance[i];

		std::cout << std::endl;
	};

	void write_to_file(std::ofstream& out, unsigned days) {	//	writes info about student in output file
		out << name;

		for(int i = 0; i < days; i++)
			out << ';' << attendance[i];

		out << std::endl;
	};
};