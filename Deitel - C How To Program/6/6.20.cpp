#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 22

enum Status {CONTINUE, WON, LOSE};

int rollDice(void);

int main(void) {

	int i;
	int sum, score, roll;
	int totalWin, totalLose;
	int won[SIZE] = { 0 };
	int lost[SIZE] = { 0 };
	float length = 0.0f;
	Status gameStatus;
	totalLose = totalWin = 0;

	srand((int)time(NULL));
	for (i = 1; i <= 1000; i++) {

		sum = rollDice();
		roll = 1;

		switch (sum) {

		case 7:
		case 11:
			gameStatus = WON;
			break;

		case 2:
		case 3:
		case 12:
			gameStatus = LOSE;

		default:
			gameStatus = CONTINUE;
			score = sum;
			break;

		}

		while (gameStatus == CONTINUE) {

			sum = rollDice();
			roll++;

			if (sum == score)
				gameStatus = WON;

			else  if (sum == 7)
				gameStatus = LOSE;

		}

		if (roll > 21)
			roll = 21;

		if (gameStatus == WON) {

			won[roll]++;
			totalWin++;

		}

		if (gameStatus == LOSE) {

			lost[roll]++;
			totalLose++;

		}

	}

	printf("Games won or lost after the 20th roll\n"
		"are displayed as the 21st roll.\n\n");

	for (i = 1; i <= 21; i++)
		printf("%3d games won and %3d games lost on %d roll.\n",
			won[i], lost[i], i);


	puts("--------------------------------------------------------");


	printf("\nThe chances of winning are %d/%d = %.2f%%\n",
		totalWin, 1000,
		100.0f * totalWin / 1000.0f);


	for (i = 1; i <= 21; i++)
		length += won[i] * i + lost[i] * i;

	printf("The average game length is %.2f rolls.\n",
		length / 1000.0);

	return 0;

}

int rollDice(void) {

	int num1, num2;
	
	num1 = 1 + rand() % 6;
	num2 = 1 + rand() % 6;

	return num1 + num2;

}