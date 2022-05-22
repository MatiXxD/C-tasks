#include <stdio.h>

void toBaseN(long num, int base);

int main(void) {

	int base;
	long num;

	printf("Enter num and base (q to exit) : ");
	while ((scanf_s("%ld %d", &num, &base)) == 2) {
		if (base < 2 || base > 10) {
			printf("Base should be in [2 ; 10].\n");
			continue;
		}
		toBaseN(num, base);
		printf("\nEnter num and base (q to exit) : ");
	}


	return 0;

}

void toBaseN(long num, int base) {

	if (num < base)
		printf("%d", num);
	else {
		toBaseN(num / base, base);
		printf("%d", num % base);
	}

}
