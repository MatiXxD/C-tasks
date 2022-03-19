#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long int integerPower(int base, unsigned int power);

int main (void) {

	int base;
	unsigned int power;

	puts("Enter base and positive power, you will get base^power");
	scanf_s("%d%d", &base, &power);

	printf("%d^%d = %d", base, power, integerPower(base, power));

	return 0;

}

long int integerPower(int base, unsigned int power) {

	long int temp = 1;

	if (power == 0)
		return 1;

	while (power--)
		temp *= base;

	return temp;

}
