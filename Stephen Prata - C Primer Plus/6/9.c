#include <stdio.h>


float calculateNum(float num1, float num2);

int main(void) {

	const char enterStr[] = "Enter two numbers : ";
	float num1, num2;

	printf("%s", enterStr);
	while ((scanf_s("%f%f", &num1, &num2) == 2) && num1 != 0 && num2 != 0)
		printf("(%f - %f) / (%f * %f) = %f\n%s", num1, num2,
			num1, num2, calculateNum(num1, num2), enterStr);

	return 0;

}

float calculateNum(float num1, float num2) {

	return (num1 - num2) / (num1 * num2);

}
