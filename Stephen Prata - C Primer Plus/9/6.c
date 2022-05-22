#include <stdio.h>

void splitValues(double* num1, double* num2, double* num3);

int main(void) {

	double num1, num2, num3;

	printf("Enter three numbers:\n");
	scanf_s("%lf %lf %lf", &num1, &num2, &num3);

	printf("Before: %lf %lf %lf\n", num1, num2, num3);
	splitValues(&num1, &num2, &num3);
	printf("Now: %lf %lf %lf", num1, num2, num3);

	return 0;

}

void splitValues(double* num1, double* num2, double* num3) {

	double max, min;
	max = min = *num1;

	if (*num2 > max)
		max = *num2;
	if (*num2 < min)
		min = *num2;
	if (*num3 > max)
		max = *num3;
	if (*num3 < min)
		min = *num3;

	*num1 = min;
	*num2 = (min + max) / 2;
	*num3 = max;

}
