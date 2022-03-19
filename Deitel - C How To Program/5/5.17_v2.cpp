#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int multiple(int a, int b);

int main (void) {

	int a, b;

	puts("Enter two integer number");
	scanf_s("%d%d", &a, &b);

	switch (multiple(a, b)) {

	case 1:
		printf("%d exactly divisible by %d", a, b);
		break;

	case 2:
		printf("%d exactly divisible by %d", b, a);
		break;

	case 404:
		printf("Nothing can't be exactly divisible");
		break;

	}

	return 0;

}

int multiple(int a, int b) {

	if (!(a % b))
		return 1;

	else if (!(b % a))
		return 2;

	else
		return 404;

}