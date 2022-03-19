#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13

int main(void) {

	int i, j;
	int num1, num2;
	int sum[SIZE] = { 0 };
	int expected[SIZE] = { 0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };

	srand((int)time(NULL));

	for (i = 1; i <= 36000; i++) {

		num1 = 1 + rand() % 6;
		num2 = 1 + rand() % 6;

		++sum[num1 + num2];

	}

	printf("%6s%12s%12s%12s\n", "Number", "Amount", "Expected", "Real");
	for (j = 2; j <= SIZE - 1; j++)
		printf("%6d%12d%11.3lf%%%11.3lf%%\n", j, sum[j], 100.0 * expected[j] / 36, 100.0 * sum[j] / 36000);

	return 0;

}