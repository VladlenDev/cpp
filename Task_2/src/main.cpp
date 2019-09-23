//	File:	main.cpp
//	Author:	Zhelezov V. D.
//	Date:	24.09.2019
//////////////////////////

#include <iostream>
#include "Tracklist.h"
#include "Gate.h"

using namespace std;

//	the only extra argument of main function is the name of csv file containing tracks in form like this:
 //////////////EXEL//////////////
//	x11	y11	x12	y12.....x1n	y1n	//
//	x21	y21	x22	y22.....x2n	y2n	//
//------------------------------//
//	xm1	ym1	xm2	ym2.....xmn	ymn	//
 ////////////////////////////////
//	where x11 y11.....xmn ymn - integer values of points coordinates
int main(int argc, char *argv[]) {

//	initializing file directory, name and path
	const string file_dir = "csv_in/";
	string file_name = argv[1];
	string file_path = file_dir + file_name;

//	initializing gate size and setting a gate
	Point plu_temp(-20, 100);
	Point prd_temp(20, -100);
	Gate ZooGate(plu_temp, prd_temp);

//	initializing tracklist
	Tracklist tracking(file_path);
	tracking.fill_list();

//	check tracks from tracklist
	while(!tracking.is_empty())
		ZooGate.check_track(tracking.get_track());
	
//	displaying counters
	cout << ZooGate.get_in_counter() << " животных зашло" << endl;
	cout << ZooGate.get_out_counter() << " животных вышло" << endl;

	return 0;
}