//	File:	Player.cpp
//	Author:	Zhelezov V. D.
//	Date:	17.10.2019
//	Type:	student code
//////////////////////////

#include "Player.h"

using namespace std;

//	throws ball by player
int Player::throw_ball(const int min_bet) {
//	throwing ball
	double alpha, speed;
	cout << name << ", enter options" << endl;
	cout << "alpha: ";
	cin >> alpha;
	cout << "speed: ";
	cin >> speed;
	Ball thrown(alpha, speed);
	current = thrown;
	cout << "Ball position: " <<
	current.get_position() << endl;
	cash -= bet;

//	check for remaining money
	if(cash < min_bet) {
		status = false;
		return -1;
	}

//	if everything is clear, return 0
	return 0;
}

//	makes bet by player
int Player::make_bet(const int min_bet) {
//	chek for remaining money
	if(cash < min_bet) {
		status = false;
		return -1;
	}

//	enter bet's size
	cout << name << ", your bet: ";
	cin >> bet;

//	if cash size is not enough, retry
	while(bet > cash) {
		cout << "You don't have " << bet <<
		", max you have is " << cash <<
		". Your bet: " << endl;
		cin >> bet;
	}

//	if bet is too low, retry
	while(bet < min_bet) {
		cout << "Minimal bet must be " <<
		min_bet << ". Your bet: ";
		cin >> bet;
	}

//	if everything is clear, return 0
	return 0;
}

//	increases player's money
int Player::increase_cash(int c) {
	cash += c;
	status = true;
	return 0;
}