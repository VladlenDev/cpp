//	File:	Point.h
//	Author:	Zhelezov V. D.
//	Date:	23.09.2019
//////////////////////////

#pragma once

//	simple struct Point of the cartesian coordinate system
struct Point {
	int x;									//	abscissa
	int y;									//	ordinate

	Point(): x(0), y(0) {};					//	constructor with zero initialization (origin)
	Point(int X, int Y): x(X), y(Y) {};		//	constructor with setpoint initialization (arguments)
};