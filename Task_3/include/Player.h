//	File:	Player.h
//	Author:	Zhelezov V. D.
//	Date:	17.10.2019
//	Type:	student code
//////////////////////////

#pragma once

#include <iostream>
#include <cstring>
#include "Ball.h"

//	objects of this class are players of Bowls game (Petang)
class Player {
private:
	std::string name;	//	player's name
	int cash;			//	player's money
	Ball current;		//	player's ball
	bool status;		//	is playing / left game
	int bet;			//	player's round bet
public:
	Player() {};						//	default constructor
	Player(std::string& n): name(n), cash(500), status(true) {};	//	name-initialization

	std::string get_name()				//	gives player's name
	{ return name; }

	int sizeofbet() 					//	gives player's bet value
	{ return bet; }

	bool is_playng()					//	gives player's status
	{ return status; }

	double get_ball_position()			//	gives player's ball's position
	{ return current.get_position(); }	

	int throw_ball(const int min_bet);	//	throws ball by player
	int make_bet(const int min_bet);	//	makes bet by player
	int increase_cash(int c);			//	increases player's money
};