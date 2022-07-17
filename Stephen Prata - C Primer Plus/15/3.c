#include <stdio.h>


int bitCount(int num);


int main(void) {

	int num;

	printf("Enter number: ");
	scanf_s("%d", &num);

	printf("Number %d has %d enabled bits.\n", num, bitCount(num));

	return 0;

}


int bitCount(int num) {

	int bitCount = 0;
	int mask = 01;

	while (mask < num) {
		if (mask & num) bitCount++;
		mask <<= 1;
	}

	return bitCount;

}
