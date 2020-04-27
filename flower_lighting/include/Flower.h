#pragma once

#include <iostream>

#define DEFAULT_FLOWER_LOCATION 0

class Flower {
private:
	bool isAlive;
	int location;

public:
	Flower(int x): isAlive(true), location(x) {}
	Flower(): isAlive(true), location(DEFAULT_FLOWER_LOCATION) {}

	void set_status(bool lifeStatus)
	{ isAlive = lifeStatus; }

	void set_location(int x)
	{ location = x; }

	bool get_status()
	{ return isAlive; }

	int get_location()
	{ return location; }

	void check_status(bool sunStatus, bool lampStatus)
	{
		if (sunStatus || lampStatus)
			set_status(true);
		else
			set_status(false);
	}

	void print_status()
	{
		std::cout << "FLOWER: ";
		isAlive ? std::cout << "ALIVE" : std::cout << "DEAD";
		std::cout << std::endl;
	}
};