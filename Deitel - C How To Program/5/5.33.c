#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void badReact(void);

void goodReact(void);

int main(void) {

	int num1, num2, answer;

	srand(time(NULL));

	num1 = 1 + rand() % 9;
	num2 = 1 + rand() % 9;
	
	printf("How much is %d times %d?\n", num1, num2);
	scanf_s("%d", &answer);

	while (answer != num1 * num2) {

		badReact();
		scanf_s("%d", &answer);

	}

	goodReact();

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