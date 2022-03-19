#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num1, num2, num3, num4, num5;
	int min, max;

	puts("Enter five integer numbers");

	scanf("%d%d%d%d%d", &num1, &num2, &num3, &num4, &num5);

	min = num1;
	if (num2 < min)
		min = num2;
	if (num3 < min)
		min = num3;
	if (num4 < min)
		min = num4;
	if (num5 < min)
		min = num5;
	
	max = num1;
	if (num2 > max)
		max = num2;
	if (num3 > max)
		max = num3;
	if (num4 > max)
		max = num4;
	if (num5 > max)
		max = num5;

	printf("Smallest is %d\n", min);
	printf("Biggest is %d\n", max);

	return 0;
}