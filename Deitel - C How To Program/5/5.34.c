#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void badReact(void);

void goodReact(void);

bool check(int num1, int num2, int answer);

int main(void) {

	int num1, num2, answer;
	int i;
	int totalCorrect, totalIncorrect;
	int percent;
	totalCorrect = totalIncorrect = 0;

	srand(time(NULL));

	for (i = 1; i <= 10; i++) {

		num1 = 1 + rand() % 9;
		num2 = 1 + rand() % 9;

		printf("How much is %d times %d?\n", num1, num2);
		scanf_s("%d", &answer);

		switch (check(num1, num2, answer)) {

		case 0:
			badReact();
			totalIncorrect++;
			break;

		case 1:
			goodReact();
			totalCorrect++;
			break;

		}

	}

	percent = totalCorrect * 10;

	printf("%s Percent of correct answers is %d.", percent > 75 ? "You get enought percent!" : "Please learn more in this theme.", percent);

	return 0;

}

void badReact(void) {

	switch (1 + rand() % 4) {

	case 1:
		puts("No. Please try again");
		break;

	case 2:
		puts("Wrong. Try once more.");
		break;

	case 3:
		puts("Don't give up!");
		break;

	case 4:
		puts("No. Keep trying.");
		break;

	}

}

void goodReact(void) {

	switch (1 + rand() % 4) {

	case 1:
		puts("Very good!");
		break;

	case 2:
		puts("Excellent!");
		break;

	case 3:
		puts("Nice work!");
		break;

	case 4:
		puts("Keep up the good work!");
		break;

	}

}

bool check(int num1, int num2, int answer) {

	if (num1 * num2 == answer)
		return 1;

	else
		return 0;

}
