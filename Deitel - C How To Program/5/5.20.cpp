#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void squre(int side, int dignit);

int main (void) {

	int side;
	char dignit;

	printf("%s", "Enter side value: ");
	scanf_s("%d", &side);

	int skip = getchar();

	printf("%s", "Enter dignit: ");
	scanf_s("%c", &dignit, 1);

	squre(side, dignit);

	return 0;

}

void squre(int side, int dignit) {

	int i;
	int temp = side;

	while (side--) {

		for (i = 1; i <= temp; i++)
			printf("%c", dignit);

		puts("");
	}

}