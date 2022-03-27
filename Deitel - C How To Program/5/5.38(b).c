#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double fibonacci(int n);

int main(void) {

	int i = 47;

	while(i)
		printf("fibonacci(%d) = %lf\n", i, fibonacci(i--));

	return 0;

}

double fibonacci(int n) {

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
