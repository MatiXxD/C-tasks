#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int perfect(int number);

int main(void) {

	int i, range;

	puts("Enter range:");
	scanf_s("%d", &range);
	
	printf("Perfect numbers in interval from 1 to %d\n", range);
	for (i = 1; i <= range; i++) 
		if (perfect(i) == i)
			printf("\t\t%d\n", i);

	return 0;

}

int perfect(int number) {

	int i;
	int sum = 0;

	for (i = 1; i < number; i++) {
		
		if (!(number % i))
			sum += i;
	}

	return sum;

}
