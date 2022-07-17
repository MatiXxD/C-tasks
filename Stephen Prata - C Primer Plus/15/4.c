#include <stdio.h>


int checkBit(int num, int pos);


int main(void) {

	int num, pos;

	printf("Enter number: ");
	scanf("%d", &num);
	printf("Now enter bit position: ");
	scanf("%d", &pos);

	printf("Bit in position %d in number %d is %c.\n", pos, num,
		checkBit(num, pos) ? '1' : '0');

	return 0;

}


int checkBit(int num, int pos) {

	unsigned mask = 0x1 << pos;

	return mask & num;

}
