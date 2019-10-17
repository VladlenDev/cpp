//	File:	Game.h
//	Author:	Zhelezov V. D.
//	Date:	17.10.2019
//	Type:	student code
//////////////////////////

#pragma once

#include "Base.h"

//	object of this class is Bowl game (Petang)
class Game {
private:
	std::vector<Player> players;	//	players container
	const int min_bet;				//	size of minimal bet
public:
	Game(std::vector<Player>& pls, int min): players(pls), min_bet(min) {};	//	initialization with options

	int play_game();				//	plays Bowls game Petang
	bool enough_players();			//	checks if there is enough num of players to start
	int check_n_kick(int& size);	//	checks players status, kicks loosers from the game
};