//	File:	task_1_main.cpp
//	Author:	Zhelezov V. D.
//	Date:	12.09.2019
//////////////////////////

#include "group.h"
using namespace std;

//	arguments of main function are *.txt filenames. Each file contanes information in form like this:
 ////////////////////////////
//	Marley B. 1 			//
//	Parker D. 0 			//
//	Yu H. 1 				//
//	Moyer J. 1 				//
//	Green G. 0 				//
//	Hawkins S. 1 			//
//	Taylor R. 1 			//
//	King S. 0 				//
//	Dreyman D. 1 			//
//	Scarsgord B. 1 			//
 ////////////////////////////
//	every string must begin with name of student and end with 1 if student attended either 0 if student was absent
int main(int argc, char* argv[]) {
	string filename[argc-1];					//	array of filenames
	string current_file;						//	variable for containing text from file
	string txt_folder = "txt_in/";				//	folder-prefix for filenames
	textfile day[argc-1];						//	array of textfiles
	group M3O_221B;								//	creating nodelist (group of students)

	for(int i = 0; i < argc - 1; i++) {			//	main loop
		filename[i] = txt_folder + argv[i+1];	//	unites folder-prefixes and filenames from arguments of main. writes results to strings array
		day[i].initialize(filename[i]);			//	initializing file using filename, writes text from file to string "filedata"
		current_file = day[i].getdata();		//	returning text from string "filedata" to "current_file"

		if(M3O_221B.is_filled() == false)		//	check if students names aren't identified
			M3O_221B.fill(current_file);			//	identification of students names

		M3O_221B.note(current_file);			//	accounting students attendance from current file (day)
	}

	M3O_221B.show();							//	print results in console
	M3O_221B.save();							//	saves results into output file

	return 0;
}