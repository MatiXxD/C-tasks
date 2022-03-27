#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

bool flip(void);

int main(void) {

	int i;
	int heads, tails;
	heads = tails = 0;

	srand(time(NULL));
	for (i = 1; i <= 100 ; i++)
		switch (flip()) {

		case 0:
			tails++;
			break;

		case 1:
			heads++;
			break;

		}

	printf("Heads\t\t%d\nTails\t\t%d\n", heads, tails);

	return 0;

}

bool flip(void) {

	return rand() % 2;

}