#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int num1, num2, num3;
	int avr;
	int min, max;

	printf("Input three different integers: ");
	scanf("%d%d%d", &num1, &num2, &num3);

	printf("Sum is %d\n", num1 + num2 + num3);

	avr = (num1 + num2 + num3) / 3;
	printf("Average is %d\n", avr);

	printf("Product is %d\n", num1 * num2 * num3);

	min = num1;
	max = num1;

	if (num2 > max)
		max = num2;

	if (num3 > max)
		max = num3;

	if (num2 < min)
		min = num2;

	if (num3 < min)
		min = num3;
	
	printf("Smallest is %d\n", min);
	printf("Biggest is %d\n", max);

	return 0;
}