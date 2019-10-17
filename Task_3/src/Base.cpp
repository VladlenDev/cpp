//	File:	Base.cpp
//	Author:	Zhelezov V. D.
//	Date:	17.10.2019
//	Type:	student code
//////////////////////////

#include "Base.h"

using namespace std;

//	compare players round results, find out winner
int Base::check_round(vector<Player>& players) {
//	initialization
	int winner_id = -1;
	double best_dist = width / 2;
	double curr_dist;

//	check round results
	for(int i = 0; i < players.size(); i++) {
	//	adding player's bet, finding out distance from base center to ball's position
		bank += players[i].sizeofbet();
		curr_dist = middle - players[i].get_ball_position();

	//	check for distance direction
		if(curr_dist < 0)
			curr_dist *= -1;

	//	compare results, telling winner's number
		if(curr_dist < best_dist) {
			best_dist = curr_dist;
			winner_id = i;
		}
	}

//	making round conclusion
	if(winner_id == -1)
		cout << "Money stay with bank" << endl;
	else {
		cout << players[winner_id].get_name() << " get " <<
		bank << endl;
		players[winner_id].increase_cash(bank);
	}

//	if everything is clear, return 0
	return 0;
}

//	print base range position
int Base::print_position() {
	cout << "New base position: " << middle - width / 2 <<
	" - " << middle + width / 2 << endl;
	return 0;
}

//	change base range position
int Base::change_position() {
	middle = rand()%100;
	width = rand()%20;
	bank = 0;
	return 0;
}