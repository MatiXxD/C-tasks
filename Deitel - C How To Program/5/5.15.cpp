#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double hypotenuse(double a, double b);

int main (void) {

	double side1, side2;

	puts("Enter two sides");
	scanf_s("%lf%lf", &side1, &side2);

	printf("Hypotenuse is %.1f", hypotenuse(side1, side2));

	return 0;

}

double hypotenuse(double a, double b) {

	return sqrt(pow(a, 2) + pow(b, 2));

}
