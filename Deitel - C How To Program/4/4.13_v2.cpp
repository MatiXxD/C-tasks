#include <stdio.h>
#include <limits.h>

int main() {

	int i, prvCompos;
	int compos = 1;

	for (i = 1; i <= 15; i += 2) {

		prvCompos = compos;
		printf("%d * %d = %d\n", prvCompos, i, compos *= i);
	}

	return 0;

}