#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#define WIDTH_MIN 5
#define WIDTH_MAX 25
#define LOCATION_MIN 5
#define LOCATION_MAX 25

class Cloud
{
protected:
	int width;
	int location;

public:
	Cloud(int w, int x): width(w), location(x) {}
	Cloud()
	{
		srand(time(NULL));

		width = rand() % WIDTH_MAX + WIDTH_MIN;
		location = rand() % LOCATION_MAX + LOCATION_MIN;
	}

	void set_width(int w)
	{ width = w; }

	void set_location(int x)
	{ location = x; }

	int get_width()
	{ return width; }

	int get_location()
	{ return location; }

	void move()
	{
		location--;
	}

	void regenerate()
	{
		Cloud temp;

		set_width(temp.width);
		set_location(temp.location);
	}

	void print_location()
	{
		std::cout << "CLOUD: (";
		std::cout << location << ";" << location + width << ")" << std::endl;
	}
};