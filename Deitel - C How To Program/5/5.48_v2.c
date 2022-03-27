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

	if (b < 0) {								

		a *= -1;													// ДЕЛАЕМ a ОТР. А b ПОЛОЖ. В ИТОГЕ ПОЛУЧАЕМ ОТР. СУММУ.
		b *= -1;

	}

	if (b == 1)
		return a;

	else
		return a + func(a, b - 1);

}