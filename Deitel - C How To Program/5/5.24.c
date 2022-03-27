#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float celsius(float fahrenhiet);

float fahrenhiet(float celsius);

int main(void) {

	int i, j;

	puts("Celsius\t\tFahrenhiet");
	for (i = 1; i <= 100; i++) 
		printf("%.2f\t\t%.2f\n", (float)i, fahrenhiet(i));

	puts("\n--------------------------------------------------\n");

	puts("Fahrenhiet\tCelsius");
	for (j = 32; j <= 212; j++)
		printf("%.2f\t\t%.2f\n", (float)j, celsius(j));

	return 0;

}

float celsius(float fahrenhiet) {

	return (fahrenhiet - 32.0f) / 1.8f;

}

float fahrenhiet(float celsius) {

	return 1.8f * celsius + 32.0f;

}
