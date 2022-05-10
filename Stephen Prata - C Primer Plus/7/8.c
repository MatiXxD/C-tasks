#include <stdio.h>

#define COEF 1.5
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25

float chooseRate(void);

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
	int choose = 0;

	while (choose < 1 || choose > 5) {

		printf("Choose rate ($ per hour):\n");
		printf("%-15s%-15s\n%-15s%-15s\n%-15s\n", "1) 8.75", "2) 9.33",
			"3) 10.00", "4) 11.20", "5) Exit");
		scanf_s("%d", &choose);

		switch (choose) {

		case 1:
			rate = 8.75;
			break;
		case 2:
			rate = 9.33;
			break;
		case 3:
			rate = 10.0;
			break;
		case 4:
			rate = 11.2;
			break;
		case 5:
			rate = -1;
			break;
		default:
			printf("Wrong option! Choose option again.\n");

		}

	}

	return rate;

}
