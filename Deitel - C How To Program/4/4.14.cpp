#include <stdio.h>
#include <limits.h>

int main() {

	int i;
	int fctl = 1;

	for (i = 1; i <= 5; i++) 
		printf("Factorial of %d : %d\n", i, fctl *= i);

	return 0;

}