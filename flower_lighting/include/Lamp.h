#pragma once

#include <iostream>

#define DEFAULT_LAMP_LOCATION 1

class Lamp
{
private:
	bool isOn;
	int location;

public:
	Lamp(int x): isOn(false), location(x) {}
	Lamp(): isOn(false), location(DEFAULT_SUN_LOCATION) {}

	void set_status(bool status)
	{ isOn = status; }

	void set_location(int x)
	{ location = x; }

	bool get_status()
	{ return isOn; }

	int get_location()
	{ return location; }

	void switch_status()
	{
		isOn ? set_status(false) : set_status(true);
	}

	void check_status(bool camSignalisation)
	{
		if (camSignalisation)
			switch_status();
	}

	void print_status()
	{
		std::cout << "LAMP: ";
		isOn ? std::cout << "ON" : std::cout << "OFF";
		std::cout << std::endl;
	}
};