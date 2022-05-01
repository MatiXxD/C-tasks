#include <stdio.h>

double cube(double n);

int main(void) {

	double num;

	printf("Enter number: ");
	scanf_s("%lf", &num);

	printf("(%.2lf)^3 = %.2lf", num, cube(num));

	return 0;

}

double cube(double n) {

	return n * n * n;

}
