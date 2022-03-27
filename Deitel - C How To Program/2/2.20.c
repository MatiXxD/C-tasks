#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int r;
	int d;
	double pi = 3.14159;
	double sqr, per;

	puts("Input radius");

	scanf("%d", &r);

	d = 2 * r;
	sqr = pi * r * r;
	per = 2 * pi * r;

	printf("Diameter is %d\nPerimeter is %f\nSquare is %f\n", d, per, sqr);

	return 0;
}