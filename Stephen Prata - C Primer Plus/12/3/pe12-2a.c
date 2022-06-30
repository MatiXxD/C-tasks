#include <stdio.h>

static void cleanBuffer() {

	while (getchar() != '\n');

}

static void showInfo(int mode, double fuelUsage, double distance) {

	double fuelConsumption;

	if (!mode)
		fuelConsumption = fuelUsage / distance * 100;
	else
		fuelConsumption = distance / fuelUsage;

	printf("Fuel consumption is %.2lf %s.\n", fuelConsumption, mode == 0 ?
		"liters per 100 km" : "miles per gallon");

}

void getInfo(int modeVal) {

	double distance, fuelUsage;
	static int mode;

	if (modeVal == 0 || modeVal == 1)
		mode = modeVal;
	else
		printf("Entered wrong mode. Program will use previous mode (%d).\n", mode);

	printf("%s", mode == 0 ? "Enter the distance traveled in kilometers: " :
		"Enter the distance traveled in miles: ");
	scanf("%lf", &distance);
	cleanBuffer();
	printf("%s", mode == 0 ? "Enter the amount of fuel used in liters: " :
		"Enter the amount of fuel used in gallons: ");
	scanf("%lf", &fuelUsage);
	cleanBuffer();

	showInfo(mode, fuelUsage, distance);

}
