#include <stdio.h>

#define EARN_PER_HOUR 10
#define COEF 1.5
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25


int main(void) {

	unsigned hours;
	float earned;
	float tax;

	printf("Enter amount of hours:\n");
	scanf_s("%u", &hours);

	if (hours <= 40)
		earned = hours * EARN_PER_HOUR;
	else
		earned = 40 * EARN_PER_HOUR + (hours - 40) * EARN_PER_HOUR * COEF;
	printf("You earned %.2f $\n", earned);

	if (earned <= 300)
		tax = earned * TAX1;
	else if (earned <= 450)
		tax = 300 * TAX1 + (earned - 300) * TAX2;
	else
		tax = 300 * TAX1 + 150 * TAX2 + (earned - 450) * TAX3;
	printf("Your tax if %.2f $\n", tax);
	printf("Earned - tax = %.2f $\n", earned - tax);

	return 0;

}
