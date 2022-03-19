#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main (void) {

	int i;

	srand((int)time(NULL));

	i = 0;
	while (i++ < 10)
		printf("%d\t", (1 + rand() % 5) * 2);
	puts("\n");

	i = 0;
	while (i++ < 10)
		printf("%d\t", (1 + rand() % 5) * 2 + 1);
	puts("\n");

	i = 0;
	while (i++ < 10)
		printf("%d\t", 6 + (rand() % 5) * 4);
	puts("\n");

	return 0;

}