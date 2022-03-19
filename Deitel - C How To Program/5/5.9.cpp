#include <stdio.h>
#include <math.h>

float ioFunc(int counter, float hour);

float parse(float hour);

int main (void) {

	float hour, hour1, hour2, hour3;
	int counter;
	float totalHour, totalCharge;
	totalHour = totalCharge = 0;

	puts("Enter hours for 3 cars:");
	scanf_s("%f%f%f", &hour1, &hour2, &hour3);

	puts("\n\n-------------------------------------------------------\n\n");

	printf("%-12s%-12s%-12s\n", "Car", "Hours", "Charge");

	for (counter = 1; counter <= 3; counter++) {

		float temp;

		if (counter == 1)
			hour = hour1;

		else if (counter == 2)
			hour = hour2;

		else
			hour = hour3;

		if (temp = ioFunc(counter, hour) > 0) {

			totalHour += hour;
			totalCharge += temp;

		}

		else
			counter = 1337;

	}

	return 0;

}

float ioFunc(int counter, float hour) {

	float charge;

	printf("%-12d", counter);
	printf("%-12.1f", hour);

	if ((charge = parse(hour)) != -1.0)
		printf("%-10.2f\n",charge);

	else {

		puts("Entered wrong hour value!");
		charge = -228;

	}

	return charge;

}

float parse(float hour) {

	if (hour >= 3 && hour <= 19)
		return 2.0f + (ceil(hour) - 3.0f) * 0.5f;

	else if (hour > 19 && hour <= 24)
		return 10.0f;

	else if (hour < 3)
		return 2.0f;

	else
		return -1.0f;

}