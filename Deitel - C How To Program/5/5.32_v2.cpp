#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

bool check(int num1, int num2);

int main(void) {

	int num1, num2;

	srand(time(NULL));

	num1 = 1 + rand() % 9;
	num2 = 1 + rand() % 9;
	while (!(check(num1, num2))) {

		num1 = 1 + rand() % 9;
		num2 = 1 + rand() % 9;

	}

	return 0;

}

bool check(int num1, int num2) {

	int answer;

	printf("%d * %d = ", num1, num2);
	scanf_s("%d", &answer);

	if (answer == num1 * num2) {

		puts("Well done!");
		return 1;

	}

	else {

		puts("Try again");
		return 0;

	}

}