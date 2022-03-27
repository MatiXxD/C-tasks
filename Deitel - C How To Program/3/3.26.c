#include <stdio.h>

int main() {

	int A = 3;

	puts("A\tA+2\tA+4\tA+6\n");

	while (A <= 15) {
		printf("%d\t%d\t%d\t%d\t\n", A, A + 2, A + 4, A + 6);
		A += 3;
	}

	return 0;
}