#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int reverse(unsigned int number);

int main(void) {

	unsigned int number;

	puts("Enter positive integer number");
	scanf_s("%u", &number);

	printf("The reverse number is %u", reverse(number));

	return 0;

}

int reverse(unsigned int number) {

	int divider = 10;
	int reverse = 0;

	while (number != 0) {

		reverse = reverse * 10 + number % divider;
		number /= 10;

	}

	return reverse;

}