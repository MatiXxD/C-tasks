#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void guess(void);

int react(int number, int guess);

bool correct(void);

void speed(int count);

int main(void) {

	int number, guessNumber;

	srand((int)time(NULL));

	guess();

	while (correct())
		guess();

	return 0;

}

int react(int number, int guess) {

	if (guess > number) {

		puts("Too big. Try again");
		return 1;

	}

	else if (guess < number) {

		puts("Too low. Try again");
		return 1;

	}

	else
		return 0;

}

bool correct(void) {

	int temp;
	static int count = 0;

	puts("Good job you have choosen the right number. Do you want to continue (1 to continue)?");
	scanf_s("%d", &temp);

	puts("\n\n---------------------------------------------\n\n");

	count++;

	if (temp == 1)
		return count;

	else {

		printf("You have guessed %d numbers!", count);
		return 0;

	}

}

void guess(void) {

	int number , guessNumber, count;

	count = 1;
	number = 1 + rand() % 1000;

	printf("%s", "I have a number from 1 to 1000.\nCan you guess it?\nPlease, enter your first guess: ");
	scanf_s("%d", &guessNumber);
	while (react(number, guessNumber)) {

		scanf_s("%d", &guessNumber);
		count++;

	}

	speed(count);

	puts("\n\n---------------------------------------------\n\n");

}

void speed(int count) {

	if (count < 10)
		puts("You are lucky or you now the secret.");

	else if (count > 10)
		puts("You can find the right number faster");

	else
		puts("You know the secret");

}