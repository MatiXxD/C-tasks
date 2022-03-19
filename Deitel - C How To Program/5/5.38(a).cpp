#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long int fibonacci(int n);

int main(void) {

	int n;

	puts("Enter numer of fibonacci number:");
	scanf_s("%d", &n);

	printf("fibonacci(%d) = %d\n", n, fibonacci(n));

	return 0;

}

long int fibonacci(int n) {

	int i;
	int a = 0;
	int b = 1;

	if (n == 1)
		return a;

	if (n == 2)
		return b;

	for (i = 1; i <= n - 2; i++) {

		int temp = b;

		b += a;
		a = temp;

	}
		 
	return b;

}
