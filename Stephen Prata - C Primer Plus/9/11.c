#include <stdio.h>

long Fibonacci(unsigned num);

int main(void) {

	unsigned num;

	printf("Enter positive number (q to exit): ");
	while (scanf_s("%u", &num) == 1) {
		if (num == 0) {
			printf("Should start from 1.\n");
			continue;
		}
		printf("Fibonacci(%u) = %ld\n", num, Fibonacci(num));
		printf("\nEnter positive number (q to exit): ");
	}

	return 0;

}

long Fibonacci(unsigned num) {

	int x1 = 1;
	int x2 = 1;

	for (int i = 2; i < num; i++) {
		int temp = x1;
		x1 = x2;
		x2 += temp;
	}

	return x2;

}
