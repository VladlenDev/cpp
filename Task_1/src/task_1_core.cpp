//	File:	task_1_core.cpp
//	Author:	Zhelezov V. D.
//	Date:	14.09.2019
//////////////////////////

#include "group.h"
using namespace std;

//	initializes file using filename, writes text from file to string "filedata"
void textfile::initialize(const string& fname) {
	filename = fname;
	filestream.open(filename);
	if(!filestream) {
		cout << "file " << filename << " not found" << endl;
		exit(1);
	}

	string temp((istreambuf_iterator<char>(filestream)), istreambuf_iterator<char>());
	filedata = temp;
}

//	destructor
group::~group() {
	student *temp;

	while(head) {
		temp = head->get_next();
		delete head;
		head = temp;
	}

	if(outfile)
		outfile.close();
}

//	identifies student's name. is used in a loop in method "fill"
void group::add(string name) {
	student *temp = new student;
	temp->regist(name);
	*temp << head;
	head = temp;

}

//	prints results in console
void group::show() {
	student *temp = head;

	while(temp) {
		temp->display(day);
		temp = temp->get_next();
	}
}

//	saves results into output file
void group::save() {
	student *temp = head;

	while(temp) {
		temp->write_to_file(outfile, day);
		temp = temp->get_next();
	}
}

//	identifies students names from text of the first file
void group::fill(string first_file) {
	string name;

	for(int i = 0; i < first_file.length(); i++) {
		while(first_file.at(i) != '0' && first_file.at(i) != '1') {
			name += first_file[i];
			i++;
		}
		name.erase(name.size()-1, 1);
		add(name);
		name.erase(0, name.size());
		i++;
	}

	names_are_filled = true;
}

//	accounts students attendance from current file (day)
void group::note(string current_file) {
	student *temp = head;
	bool attendance;
	int i;

	while(temp) {
		i = current_file.find(temp->getname());

		if(i == -1)
			attendance = false;
		else {
			while(current_file.at(i) != '0' && current_file.at(i) != '1')
				i++;

			if(current_file[i] == '1')
				attendance = true;
			else
				attendance = false;
		}

		temp->note(day, attendance);
		temp = temp->get_next();
	}

	day++;
}