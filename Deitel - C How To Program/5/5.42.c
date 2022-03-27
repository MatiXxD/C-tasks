#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int gcd(int x, int y);

int max(int num1, int num2);

int min(int num1, int num2);

int main(void) {

	int num1, num2;

	puts("Enter two integer numbers:");
	scanf_s("%d%d", &num1, &num2);

	printf("gcd(%d, %d) = %d", num1, num2, gcd(max(num1, num2), min(num1, num2)));

	return 0;

}

int gcd(int x, int y) {

	if (y == 0)
		return x;

	else
		return gcd(y, x % y);

}

int max(int num1, int num2) {

	if (num1 >= num2)
		return num1;

	else
		return num2;

}

int min(int num1, int num2) {

	if (num1 <= num2)
		return num1;

	else
		return num2;

}