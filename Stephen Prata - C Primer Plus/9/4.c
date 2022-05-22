#include <stdio.h>

double avgHarmonic(double num1, double num2);

int main(void) {

	double num1, num2;

	printf("Enter two numbers:\n");
	scanf_s("%lf %lf", &num1, &num2);

	printf("Average harmonic number is %.2lf\n",
		avgHarmonic(num1, num2));

	return 0;

}

double avgHarmonic(double num1, double num2) {

	return 1.0 / ((1.0 / num1 + 1.0 / num2) / 2);

}
