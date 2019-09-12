//	File:	task_1_head.h
//	Author:	Zhelezov V. D.
//	Date:	12.09.2019
//////////////////////////
#include <fstream>
#include <iostream>
#include <streambuf>
#include <cstring>
#include <iomanip>
using namespace std;

//	simple class for easy reading and transforming textfiles
class textfile {
private:
	string filename, filedata;		//	containing filename and filedata (text) respectively
	ifstream filestream;			//	input textfile
public:
	textfile()						//	constructor
	{ };
	~textfile()						//	destructor
	{ filestream.close(); };

	void initialize(string fname);	//	initializes file using filename, writes text from file to string "filedata"
	string getdata()				//	returns text from string "filedata" to calling environment
	{ return filedata; };
};

//	objects of this class are nodes
class student {
private:
	string name;			//	name of student essentially is personal identificator
	enum {DAYS = 10};		//	unusual representation of constant. is used just for array below
	bool attendance[DAYS];	//	student attendance accounting
public:
	student *next;			//	connection in nodelist

	void regist(string nm)								//	initializes student's name
	{ name = nm; };

	string getname()									//	returnes student's name to calling environment
	{ return name; };

	void note(unsigned day, bool attend)				//	accounts student's attendance
	{ if(day < 20) attendance[day] = attend; };

	void display(unsigned days) {						//	prints information about student in console
		cout << setw(20) << name << '\t';

		for(int i = 0; i < days; i++)
			cout << ' ' << attendance[i];

		cout << endl;
	};

	void write_to_file(ofstream& out, unsigned days) {	//	writes info about student in output file
		out << setw(20) << name << '\t';

		for(int i = 0; i < days; i++)
			out << ' ' << attendance[i];

		out << endl;
	};
};

//	objects of this class are nodelists
class group {
private:
	student *head;			//	head of nodelist
	unsigned day;			//	count of days (files incuding attendance)
	bool names_are_filled;	//	variable for chek if students names are identified either not
	ofstream outfile;		//	file to save results
public:
	group(): head(NULL), day(0), names_are_filled(false), outfile("txt_out/attendance_group_M3O-221B-18.txt")
	{};								//	constructor
	~group();						//	destructor

	void add(string name);			//	identifies student's name. is used in a loop in method "fill"
	void show();					//	prints results in console
	void fill(string first_file);	//	identifies students names from text of the first file
	void note(string current_file);	//	accounts students attendance from current file (day)
	bool is_filled()				//	checks if student names are identified or not
	{ return names_are_filled; };

	void save();					//	saves results into output file
};