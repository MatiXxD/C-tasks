#include <stdio.h>

int main(void) {

	unsigned years = 0;
	double balance = 1E6;

	while (balance > 0) {
		balance = (balance + balance * 0.08) - 1E5;
		years++;
	}

	printf("After %u years balance become empty.\n", years);

	return 0;

}
