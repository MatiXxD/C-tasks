#include <stdio.h>
#include <limits.h>

int main() {

	int i;
	int compos = 1;

	for (i = 1; i <= 15; i += 2) {

		compos *= i;
		printf("The composition of the %d numbers is %d\n", i, compos);
	}

	return 0;

}