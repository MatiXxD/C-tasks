#include <stdio.h>


int main(void) {

	const char enterStr[] = "Enter bottom and top numbers (should be integer): ";
	int bot, top;

	printf("%s", enterStr);
	while ((scanf_s("%d%d", &bot, &top) == 2) && bot < top) {

		long tempSum = 0;
		for (int num = bot; num <= top; num++)
			tempSum += num * num;

		printf("For bot^2 = %d and top^2 = %d sum is %ld.\n%s", bot * bot, top * top,
			tempSum, enterStr);
	}

	return 0;

}
