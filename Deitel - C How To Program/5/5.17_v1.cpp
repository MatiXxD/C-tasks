#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int multiple(int a, int b);

int main (void) {

	int a, b;

	puts("Enter two integer number");
	scanf_s("%d%d", &a, &b);

	if (multiple(a, b))
		printf("%d is exactly devidable by %d\n", a, b);

	else
		printf("%d can't be exactly devidable by %d\n", a, b);

	return 0;

}

int multiple(int a, int b) {

	return !(a % b);

}