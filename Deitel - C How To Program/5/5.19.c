#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void squre(int side);

int main (void) {

	int side;

	printf("%s", "Enter side value: ");
	scanf_s("%d", &side);

	squre(side);

	return 0;

}

void squre(int side) {

	int i;
	int temp = side;

	while (side--) {

		for (i = 1; i <= temp; i++)
			printf("*");

		puts("");
	}

}