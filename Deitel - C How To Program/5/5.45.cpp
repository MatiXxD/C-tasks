#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float distance(float x1, float y1, float x2, float y2);

float absIncr(float num1, float num2);

int main(void) {

	float x1, x2, y1, y2;

	puts("Enter first point (x1, y1)");
	scanf_s("%f%f", &x1, &y1);
	puts("Enter first point (x2, y2)");
	scanf_s("%f%f", &x2, &y2);

	printf("Distance betwwen (%.2f ; %.2f) and (%.2f ; %.2f) is %f", x1, y1, x2, y2, distance(x1, y1, x2, y2));

	return 0;

}

float distance(float x1, float y1, float x2, float y2) {

	float x, y, distance;

	x = absIncr(x1, x2);
	y = absIncr(y1, y2);

	distance = sqrt(pow(x, 2) + pow(y, 2));

	return distance;

}

float absIncr(float num1, float num2) {

	if (num1 > num2)
		return num1 - num2;

	else
		return num2 - num1;

}