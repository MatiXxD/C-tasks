#include <stdio.h>

double min(double num1, double num2);

int main(void) {

	double num1, num2;

	printf("Enter two numbers: ");
	scanf_s("%lf %lf", &num1, &num2);
	printf("Min is %.2lf", min(num1, num2));

	return 0;

}

double min(double num1, double num2) {

	return num1 > num2 ? num2 : num1;

}
