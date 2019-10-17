//	File:	Base.h
//	Author:	Zhelezov V. D.
//	Date:	17.10.2019
//	Type:	student code
//////////////////////////

#pragma once

#include <vector>
#include "Player.h"

//	objects of this class are playfields of Bowls game (Petang)
class Base {
private:
	int middle;	//	center of win area
	int width;	//	size of win area
	int bank;	//	round money
public:
	Base(int x, int w): middle(x), width(w), bank(0) {};	//	initialization with options

	int check_round(std::vector<Player>& players);	//	compare players round results, find out winner
	int print_position();							//	print base range position
	int change_position();							//	change base range position
};