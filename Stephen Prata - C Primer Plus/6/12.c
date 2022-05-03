#include <stdio.h>
#include <math.h>

int main(void) {

	int count;
	double sum1 = 0;
	double sum2 = 0;

	printf("Enter count of elements: ");
	while (scanf_s("%d", &count) == 1 && count >= 0) {

		printf("%6s%8s%8s\n", "Count", "Sum1", "Sum2");
		for (int i = 1; i <= count; i++) {

			sum1 += 1.0 / i;
			sum2 += pow(-1.0, i+1) * (1.0 / i);
			printf("%6d%8.4lf%8.4lf\n", i, sum1, sum2);

		}

		sum1 = sum2 = 0;
		printf("\n-------------------------------\n\n"
			"Enter count of elements: ");

	}


	return 0;

}
