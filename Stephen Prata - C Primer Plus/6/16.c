#include <stdio.h>

int main(void) {

	double sum1 = 100;
	double sum2 = 100;
	int years = 0;

	while (sum1 >= sum2) {

		sum1 += 100 * 0.1;
		sum2 += sum2 * 0.05;

		years++;

	}
	printf("After %d years: sum2 (%.2lf) > sum1 (%.2lf)\n", years, sum2, sum1);

	return 0;

}
