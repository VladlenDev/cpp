#pragma once

#include <iostream>

#define DEFAULT_SUN_LOCATION 0

class Sun
{
private:
	bool isShining;
	int location;

public:
	Sun(int x): isShining(true), location(x) {}
	Sun(): isShining(true), location(DEFAULT_SUN_LOCATION) {}

	void set_status(bool status)
	{ isShining = status; }

	void set_location(int x)
	{ location = x; }

	bool get_status()
	{ return isShining; }

	int get_location()
	{ return location; }

	void check_status(int cloudLocation, int cloudWidth)
	{
		if (location >= cloudLocation && location <= cloudLocation + cloudWidth)
			set_status(false);
		else
			set_status(true);
	}

	void print_status() {
		std::cout << "SUN: ";
		isShining ? std::cout << "" : std::cout << "NOT ";
		std::cout << "SHINING" << std::endl;
	}
};