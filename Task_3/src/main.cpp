//	File:	main.cpp
//	Author:	Zhelezov V. D.
//	Date:	17.10.2019
//	Type:	student code
//////////////////////////

#include <ctime>
#include "Game.h"

using namespace std;

void print_usage(char* exec_name);	//	prints usage info of this execution

//	the first argument of main function is a minimal bet value
//	next arguments of main function are players names
//	there must be at least 2 players at the beginning
//	at the beginning each player has 500$
// 	every round goes in 3 steps:
//		1) players make their bets
//		2) players throw their balls
//		3) player, whoes ball is nearest to middle of base win a round
//	when there is no at least 2 players, who can make a bet, game is over
int main(int argc, char* argv[]) {
//	check for correct num of args
	if(argc < 3) {
		print_usage(argv[0]);
		return -1;
	}

//	initialization of input data
	srand(time(NULL));
	vector<Player> players;
	const string sMin_bet = argv[1];
	int min_bet = stoi(sMin_bet);
	string name[argc-2];
	Player temp;

//	filling container of players
	for(int i = 2; i < argc; i++) {
		name[i-2] = argv[i];
		temp = name[i-2];
		players.push_back(temp);
	}

//	playing game
	Game bowls(players, min_bet);
	bowls.play_game();

//	if everything is clear, return 0
	return 0;
}

void print_usage(char* exec_name) {
//	print usage info message
	cout << endl << "USAGE:" << endl;
	cout << exec_name << " [NUM_OF_MIN_BET]" <<
	" [PLAYER_1_NAME] [PLAYER_2_NAME] ..." << endl << endl;
}