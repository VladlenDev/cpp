//	File:	Game.cpp
//	Author:	Zhelezov V. D.
//	Date:	17.10.2019
//	Type:	student code
//////////////////////////

#include "Game.h"

using namespace std;

//	plays Bowls game Petang
int Game::play_game() {
//	check if there is enough num of players to start
	if(!enough_players()) {
		cout << "Minimal number of players required: 2" << endl;
		return -1;
	}

//	initialization
	int size = players.size();
	Base sandbox(rand()%100, rand()%20);
	string win_name = "Bank";
	Player winner(win_name);

//	main game algorithm
	while(size > 1) {
	//	check if second player is in game to print base range position
		if(players[1].is_playng())
			sandbox.print_position();

	//	let players make bets
		for(int i = 0; i < size; i++)
			players[i].make_bet(min_bet);

	//	let players throw balls
		for(int i = 0; i < size; i++)
			players[i].throw_ball(min_bet);

	//	check round results, change base range position
		if(size > 1) {
			sandbox.check_round(players);
			sandbox.change_position();
		}

	//	check players status, kick loosers
		check_n_kick(size);
	}

//	check if winner is exist
	if(players[0].is_playng())
		winner = players[0];

//	report winner's name
	cout << winner.get_name() << " won!" << endl;
	return 0;
}

//	checks if there is enough num of players to start
bool Game::enough_players() {
	return (players.size() >= 2) ? true : false;
}

//	checks players status, kicks loosers from the game
int Game::check_n_kick(int& size) {
//	initializing buffer variable for permutations
	Player buf;

//	check, kick, erase number of players
	for(int i = 0; i < size; i++) {
		if(!players[i].is_playng()) {
			buf = players[i];
			players[i] = players[size-1];
			players[size-1] = buf;
			players.erase(players.begin() + --size);
		}	
	}

//	if everything is clear, return 0
	return 0;
}