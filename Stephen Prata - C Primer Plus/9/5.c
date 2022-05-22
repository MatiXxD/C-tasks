#include <stdio.h>

void larger_of(double *num1, double *num2);

int main(void) {

	double num1, num2;

	printf("Enter two numbers:\n");
	scanf_s("%lf %lf", &num1, &num2);

	printf("\nBefore: %lf %lf\n", num1, num2);
	larger_of(&num1, &num2);
	printf("Now: %lf %lf", num1, num2);

	return 0;

}

void larger_of(double *num1, double *num2) {

	if (*num1 > *num2)
		*num2 = *num1;
	else
		*num1 = *num2;

}
