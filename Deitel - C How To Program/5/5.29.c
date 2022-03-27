#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int gcd(unsigned int num1, unsigned int num2);

int fastGcd(unsigned int num1, unsigned int num2);

double max(unsigned int num1, unsigned int num2);

double min(unsigned int num1, unsigned int num2);

int main(void) {

	unsigned int num1, num2;

	puts("Enter two integer numbers");
	scanf_s("%d%d", &num1, &num2);

	printf("The greatest common factor is %d\n", gcd(num1, num2));
	printf("The greatest common factor is %d\n", fastGcd(num1, num2));


	return 0;

}

double max(unsigned int num1, unsigned int num2) {

	if (num2 > num1)
		return num2;

	else
		return num1;

}

double min(unsigned int num1, unsigned int num2) {

	if (num2 < num1)
		return num2;

	else
		return num1;

}

int gcd(unsigned int num1, unsigned int num2) {

	int i;
	int maxDivider = 228;

	for (i = 1; i <= min(num1, num2); i++) {

		if ((num1 % i == 0) && (num2 % i == 0))
			maxDivider = i;

	}

	return maxDivider;
}

int fastGcd(unsigned int num1, unsigned int num2) {

	int i;
	int maxDivider = 228;

	for (i = 1; i <= (int)sqrt(max(num1, num2)); i++) {

		if ((num1 % i == 0) && (num2 % i == 0))
			maxDivider = i;

	}

	if ((int)max(num1, num2) % (int)min(num1, num2) == 0)
		return (int)min(num1, num2);


	return maxDivider;

}