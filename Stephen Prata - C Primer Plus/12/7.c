#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cleanBuffer();
void getValues(int* diceCount, int* sideCount);
int throwDice(int diceCount, int sideCount);

int main(void) {

	srand((unsigned int)time(NULL));

	int throwsNum;

	printf("Enter the number of rolls or q to exit: ");
	while (scanf("%d", &throwsNum) == 1) {

		int i;
		int diceCount, sideCount;

		getValues(&diceCount, &sideCount);

		printf("We have %d throws of %d dice with %d sides.\n",
			throwsNum, diceCount, sideCount);
		for (i = 0; i < throwsNum; i++) {
			printf("%4d", throwDice(diceCount, sideCount));
			if (!((i + 1) % 10))
				putchar('\n');
		}
		if ((i + 1) % 10)
			putchar('\n');


		printf("Enter the number of rolls or q to exit: ");

	}

	return 0;

}

void cleanBuffer() {

	while (getchar() != '\n') continue;

}

void getValues(int* diceCount, int* sideCount) {

	printf("How many sides and how many dices? ");
	while (scanf("%d %d", sideCount, diceCount) != 2 || *sideCount <= 1 || *diceCount <= 0) {
		printf("Wrong input. Try again: ");
		cleanBuffer();
	}

}

int throwDice(int diceCount, int sideCount) {

	int total = 0;

	for (int i = 0; i < diceCount; i++)
		total += 1 + rand() % sideCount;

	return total;

}
