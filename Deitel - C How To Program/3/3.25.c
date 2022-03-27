#include <stdio.h>

int main() {

	int n = 1;

	puts("N\t10*N\t100*N\t1000*N\n");

	while (n <= 10) {
		printf("%d\t%d\t%d\t%d\t\n", n, n*10, n*100, n*1000);
		n++;
	}

	return 0;
}