#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int number;
	int a, b, c, d, e;

	puts("Enter number with from 10000 to 99999");

	scanf("%d", &number);

	a = number / 10000;
	b = (number - a * 10000) / 1000;
	c = (number - a * 10000 - b * 1000) / 100;
	d = (number - a * 10000 - b * 1000 - c * 100) / 10;
	e = number - a * 10000 - b * 1000 - c * 100 - d * 10;

	printf("%d %d %d %d %d", a, b, c, d, e);

	return 0;
}