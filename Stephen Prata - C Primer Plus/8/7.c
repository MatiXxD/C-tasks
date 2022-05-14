#include <stdio.h>
#include <ctype.h>

#define COEF 1.5f
#define TAX1 0.15f
#define TAX2 0.20f
#define TAX3 0.25f

float chooseRate(void);
int get_first(void);

int main(void) {

	unsigned hours;
	float earned, tax;
	float rate = 0;

	while (1) {

		rate = chooseRate();
		if (rate == -1)
			break;

		printf("Enter amount of hours:\n");
		scanf_s("%u", &hours);
		putchar('\n');

		if (hours <= 40)
			earned = hours * rate;
		else
			earned = 40 * rate + (hours - 40) * rate * COEF;
		printf("You earned %.2f $\n", earned);

		if (earned <= 300)
			tax = earned * TAX1;
		else if (earned <= 450)
			tax = 300 * TAX1 + (earned - 300) * TAX2;
		else
			tax = 300 * TAX1 + 150 * TAX2 + (earned - 450) * TAX3;
		printf("Your tax if %.2f $\n", tax);
		printf("Earned - tax = %.2f $\n\n\n", earned - tax);

	}

	return 0;

}

float chooseRate(void) {

	float rate;
	int choose;

	printf("Choose rate ($ per hour):\n");
	printf("%-15s%-15s\n%-15s%-15s\n%-15s\n", "a) 8.75", "b) 9.33",
		"c) 10.00", "d) 11.20", "q) Exit");
	choose = tolower(get_first());
	while (choose != 'a' && choose != 'b' && choose != 'c' && choose != 'd' && choose != 'q')
		choose = tolower(get_first());

	switch (choose) {
	case 'a':
		rate = 8.75f;
		break;
	case 'b':
		rate = 9.33f;
		break;
	case 'c':
		rate = 10.0f;
		break;
	case 'd':
		rate = 11.2f;
		break;
	case 'q':
		rate = -1.0f;
		break;
	default:
		printf("Error (got EOF).\n");
		rate = -2.0f;
	}

	return rate;

}

int get_first(void) {

	int ch;

	ch = getchar();
	while (isspace(ch))
		ch = getchar();

	return ch;

}
