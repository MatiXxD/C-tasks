#include <stdio.h>
#include <limits.h>

int main() {

	int i;
	int sum = 0;

	for (i = 2; i <= 30; i += 2) {

		sum += i;
		printf("The sum of the %d numbers is %d\n", i, sum);
	}

	return 0;

}