#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char getOption(void);
bool isvalid(char option);
void skip(void);

int main(void) {

	char option = getOption();
	while (option != 'q') {

		float num1, num2;
		printf("Now enter two numbers: ");
		while (scanf_s("%f%f", &num1, &num2) != 2) {
			printf("Wrong input. Try again: ");
			skip();
		}

		switch (option) {

		case 'a':
			printf("%.2f + %.2f = %.2f\n\n", num1, num2, num1 + num2);
			break;
		case 's':
			printf("%.2f - %.2f = %.2f\n\n", num1, num2, num1 - num2);
			break;
		case 'm':
			printf("%.2f * %.2f = %.2f\n\n", num1, num2, num1 * num2);
			break;
		case 'd':
			if (num2 != 0)
        printf("\n%.2f / %.2f = %.2f\n\n", num1, num2, num1 / num2);
			else
        printf("Can't divide by zero\n\n");

		}

		option = getOption();

	}

	return 0;

}

char getOption(void) {

	char option;
	printf("Enter option:\na) Addition\ns) Subtraction\nm) Multiplication\n"
		"d) Division\nq) Quit\n\nInput: ");

	option = tolower(getchar());
	while (!isvalid(option))
		option = tolower(getchar());

	skip();

	return option;

}

bool isvalid(char option) {

	switch (option) {

	case 'a':
	case 's':
	case 'm':
	case 'd':
	case 'q':
		return true;

	default:
		return false;

	}

}

void skip(void) {

	while (getchar() != '\n') continue;                                            // Clean buffer

}
