//	File:	Gate.h
//	Author:	Zhelezov V. D.
//	Date:	23.09.2019
//////////////////////////

#pragma once

#include <vector>
#include "Point.h"	//	including struct Point

//	Visiable tracking zone with in-side (left), out-side (right) and gate-line(middle)
class Gate {
private:
	Point posLU;	//	upper left corner of the tracking zone
	Point posRD;	//	bottom right corner of the tracking zone
	float xGate;	//	abscissa of the middle of the tracking zone
	int incnt;		//	incoming track counter
	int outcnt;		//	outgoing track counter
public:
	Gate(Point plu, Point prd);						//	constructor

	void check_track(std::vector<Point> track);		//	checks a track for entry or exit
	void reset_counters();							//	resets counters to '0'
	int get_in_counter();							//	returns value of incoming track counter
	int get_out_counter();							//	returns value of outgoing track counter
};