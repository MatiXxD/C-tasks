#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double min(double num1, double num2, double num3);

int main(void) {

	double num1, num2, num3;

	puts("Enter three number:");
	scanf_s("%lf%lf%lf", &num1, &num2, &num3);
	printf("The min number is %.3f", min(num1, num2, num3));

	return 0;

}

double min(double num1, double num2, double num3) {

	double min;

	min = num1;

	if (num2 < min)
		min = num2;

	if (num3 < min)
		min = num3;

	return min;

}