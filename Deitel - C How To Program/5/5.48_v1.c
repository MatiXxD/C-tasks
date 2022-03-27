#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int func(int a, int b);

int main(void) {

	int a, b;

	puts("Enter two integer number");
	scanf_s("%d%d", &a, &b);

	printf("%d", func(a, b));

	return 0;

}

int func(int a, int b) {

	if (b == 1)
		return a;

	else if (b > 0)
		return a + func(a, b - 1);

	else if (b < 0)
		return -(a + func(a, b + 1));

	else
		return 0;

}