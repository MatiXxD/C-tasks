#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

	int i;
	int j;
	int k;

	for (i = 1; i <= 10; i++) {

		j = i;
		while (j--)
			printf("*");

		puts("");

	}

	puts("\n\n\n");

	for (i = 10; i >= 1; i--) {

		j = i;
		while (j--)
			printf("*");

		puts("");

	}

	puts("\n\n\n");

	for (i = 1; i <= 10; i++) {

		k = 10 + 1 - i;
		j = i;
		while (--j)
			printf(" ");
		while (k--)
			printf("*");

		puts("");

	}

	puts("\n\n\n");

	for (i = 10; i >= 1; i--) {

		k = 10 + 1 - i;
		j = i;
		while (--j)
			printf(" ");
		while (k--)
			printf("*");

		puts("");

	}

	return 0;

}