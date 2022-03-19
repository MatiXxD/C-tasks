#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

	int number;
	int i, j;

	puts("You have to enter 5 integer numbers (from 1 to 30)");

	for (i = 1; i <= 5; i++) {

		printf("Enter %d number: ", i);
		scanf_s("%d", &number);

		while (number--)
			printf("*");

		puts("\n");

	}

	return 0;

}