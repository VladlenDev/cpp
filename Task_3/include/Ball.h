//	File:	Ball.h
//	Author:	Zhelezov V. D.
//	Date:	17.10.2019
//	Type:	student code
//////////////////////////

#pragma once

#include <cmath>

//	objects of this class are just x-coordinate dots
class Ball {
private:
	double position;	//	x-coordinate after throw
public:
	Ball() {};							//	default constructor
	Ball(double alpha, double speed);	//	initialization by flight from (0;0)

	double get_position()				//	gives current position
	{ return position; }
};