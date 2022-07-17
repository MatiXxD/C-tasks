#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define UINT_BITS CHAR_BIT * sizeof(unsigned int)


void rotate_l(unsigned int* num, int rep);
void printBytes(unsigned int num, int size);


int main(void) {

	unsigned int number, repeat;

	printf("Enter your number: ");
	while (scanf("%d", &number) == 1) {

		printf("How much do you want to move bits: ");
		scanf("%d", &repeat);

		puts("Before rotate_l():");
		printBytes(number, UINT_BITS);
		puts("After rotate_r():");
		rotate_l(&number, repeat);
		printBytes(number, UINT_BITS);
		putchar('\n');

		printf("Enter next number (not a number to stop): ");

	}

	return 0;

}


void rotate_l(unsigned int* num, int rep) {

	bool lastBit;
	unsigned int mask = 0x1;

	while (rep--) {
		lastBit = (*num >> UINT_BITS - 1) & mask;
		*num <<= 1;
		*num += lastBit;
	}

}

void printBytes(unsigned int num, int size) {

	unsigned int mask = 0x1 << size - 1;

	for (int i = 0; i < size; mask >>= 1) {
		printf("%c", num & mask ? '1' : '0');
		if (++i % 8 == 0) putchar(' ');
	}

	putchar('\n');

}
