//	File:	Gate.cpp
//	Author:	Zhelezov V. D.
//	Date:	24.09.2019
//////////////////////////

#include "Gate.h"

//	for clarity check
#define IN false
#define OUT true

using namespace std;

//	constructor
Gate::Gate(Point plu, Point prd): posLU(plu), posRD(prd), incnt(0), outcnt(0) {
	xGate = posLU.x + (posRD.x - posLU.x) / 2;		//	abscissa of the middle (gates) of the tracking zone
}

//	checks a track for entry or exit
void Gate::check_track(vector<Point> track) {
	bool start, finish;					//	side of first and last points of a track

//	check the side of the first point of a track
	if(track[0].x < xGate)
		start = IN;
	else
		start = OUT;

//	check the side of the last point of a track
	if(track[track.size()-1].x < xGate)
		finish = IN;
	else
		finish = OUT;

//	registration of entry or exit
	if(!start && finish)	
		outcnt++;
	else if(start && !finish)
		incnt++;
	else
		return;
}

//	resets counters to '0'
void Gate::reset_counters() {
	incnt = 0;
	outcnt = 0;
}

//	returns value of incoming track counter
int Gate::get_in_counter() {
	return incnt;
}

//	returns value of outgoing track counter
int Gate::get_out_counter() {
	return outcnt;
}