#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {

	int num1, num2, answer;

	srand(time(NULL));

	num1 = 1 + rand() % 9;
	num2 = 1 + rand() % 9;
	
	printf("How much is %d times %d?\n", num1, num2);
	scanf_s("%d", &answer);

	while (answer != num1 * num2) {

		puts("Try again");
		scanf_s("%d", &answer);

	}

	puts("Well done!");

	return 0;

}