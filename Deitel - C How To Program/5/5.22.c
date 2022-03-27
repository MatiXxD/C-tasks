#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void output(int number);

int dignitAmount(int number);

void getDignit(int dignitNumber, int number);

int main(void) {

	int number;

	printf("%s", "Enter five-sign number:");
	scanf_s("%d", &number);

	output(number);

	return 0;

}

int dignitAmount(int number) {

	int amount = 1;
	int divider = 10;

	while (number - divider > 0) {

		amount++;
		divider *= 10;

	}

	return amount;

}

void getDignit(int dignitNumber, int number) {

	switch (dignitNumber) {

	case 1:
		printf("%d  ", number / 10000);
		break;

	case 2:
		printf("%d  ", (number % 10000 - number % 1000) / 1000);
		break;

	case 3:
		printf("%d  ", (number % 1000 - number % 100) / 100);
		break;

	case 4:
		printf("%d  ", (number % 100 - number % 10) / 10);
		break;

	case 5:
		printf("%d  ", number % 10);
		break;

	}

}

void output(int number) {

	int count;
	int dignitNum;

	count = dignitAmount(number);
	
	if (count > 5) {

		puts("You entered number bigger than five-dignit.");
		return;

	}

	dignitNum = 6 - count;

	while (count--) {

		getDignit(dignitNum, number);
		dignitNum++;

	}

}