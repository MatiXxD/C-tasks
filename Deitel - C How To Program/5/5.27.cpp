#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

bool simple(int number);

bool fastSimple(int number);

int main(void) {

	int t;
	int i, j;
	int dt1, dt2;

	t = time(NULL);
	for (i = 1; i <= 300000; i++)
		if (simple(i))
			printf("\t\t%d number is simple\n", i);

	dt1 = time(NULL) - t;

	puts("\n\n\n-----------------------------------\n\n\n");
	
	t = time(NULL);
	for (i = 1; i <= 300000; i++)
		if (fastSimple(i))
			printf("\t\t%d number is simple\n", i);

	dt2 = time(NULL) - t;
	printf("Time for complete fast func is %d sek and %d sek for slow one\n", dt2, dt1);

	return 0;

}

bool simple(int number) {

	int i;

	for (i = 2; i <= number / 2; i++)
		if (number % i == 0)
			return 0;

	return 1337;

}

bool fastSimple(int number) {

	int i;

	for (i = 2; i <= (int)sqrt((double)number); i++)
		if (number % i == 0)
			return 0;

	return 1337;

}