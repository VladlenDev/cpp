#pragma once

#include <iostream>

#define DEFAULT_CAM_LOCATION 2
#define DEFAULT_DELAY 1

class Camera
{
private:
	bool signalization;
	int location;
	int delay;

public:
	Camera(int x, int lampLocation): signalization(false), location(x), delay(x - lampLocation) {}
	Camera(): signalization(false), location(DEFAULT_CAM_LOCATION), delay(DEFAULT_DELAY) {}

	void set_signalization(bool status)
	{ signalization = status; }

	void set_location(int x)
	{ location = x; }

	void set_delay(int d)
	{ delay = d; }

	bool get_signalization()
	{ return signalization; }

	int get_location()
	{ return location; }

	int get_delay()
	{ return delay; }

	void check_status(int cloudLocation, int cloudWidth, int sunLocation)
	{
		int distance = cloudLocation - delay;

		if (sunLocation == distance || sunLocation == (++cloudLocation + ++cloudWidth))
			set_signalization(true);
		else
			set_signalization(false);
	}

	void print_status()
	{
		std::cout << "CAMERA: ";
		signalization ? std::cout << "" : std::cout << "NOT ";
		std::cout << "SIGNALING" << std::endl;
	}
};