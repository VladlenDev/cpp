#include <unistd.h>
#include "Cloud.h"
#include "Flower.h"
#include "Sun.h"
#include "Camera.h"
#include "Lamp.h"

#define CLOUD_GENERATION_DELAY 10
#define SLEEP_MICROSECONDS 500000

using namespace std;

int main(int argc, char * argv[])
{
	Flower flwr;
	Lamp lmp;
	Cloud cld;
	Camera cam;
	Sun sun;

	while(flwr.get_status())
	{
		cld.move();
		cam.check_status(cld.get_location(), cld.get_width(), sun.get_location());
		sun.check_status(cld.get_location(), cld.get_width());
		lmp.check_status(cam.get_signalization());
		flwr.check_status(sun.get_status(), lmp.get_status());

		cld.print_location();
		cam.print_status();
		sun.print_status();
		lmp.print_status();
		flwr.print_status();

		if (cld.get_location() + cld.get_width() + CLOUD_GENERATION_DELAY < sun.get_location())
		{
			cld.regenerate();
			cout << "NEW CLOUD ON THE SKY!" << endl;
		}

		usleep(SLEEP_MICROSECONDS);
		system("clear");
	}

	return 0;
}