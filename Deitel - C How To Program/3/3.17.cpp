#include <stdio.h>

int main() {
	
	float distance, consumption;
	float totalDistance = 0; 
	float totalConsumption = 0;

	puts("Enter petrol consumption (-1 to stop input)");

	scanf_s("%f", &consumption);

	while (consumption != -1) {

		puts("Enter distance");
		scanf_s("%f", &distance);

		totalDistance += distance;
		totalConsumption += consumption;

		printf("For this station distance/petrol is %.2f\n\n", distance / consumption);

		puts("Enter petrol consumption (-1 to stop input)");
		scanf_s("%f", &consumption);
	}
	
	if (totalDistance == 0)
		printf("\nYou didn't enter anything\n");
	else
		printf("\nAverage distance/petrol is %.2f\n", totalDistance / totalConsumption);

	return 0;
}