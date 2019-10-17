//	File:	Ball.cpp
//	Author:	Zhelezov V. D.
//	Date:	17.10.2019
//	Type:	student code
//////////////////////////

#include "Ball.h"

using namespace std;

//	Math constants
static const double g = 9.8;
static const double deg_to_rad = 0.0175;

//	initialization by flight from (0;0)
Ball::Ball(double alpha, double speed) {
//	turn from degree to radical form and find distance between 0 and fall
	alpha *= deg_to_rad;
	position = speed * speed * sin(2*alpha) / g;
};