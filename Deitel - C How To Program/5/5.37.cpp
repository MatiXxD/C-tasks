#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int power(int base, int exponent);

int main(void) {

	int base;
	unsigned int exponent;

	puts("Enter base and exponent you will get base^exponent");
	scanf_s("%d%u", &base, &exponent);

	printf("%d^%u = %d", base, exponent, power(base, exponent));

	return 0;

}

int power(int base, int exponent) {

	if (exponent == 0)
		return 1;

	if (exponent == 1)
		return base;
	
	return base * power(base, exponent - 1);

}