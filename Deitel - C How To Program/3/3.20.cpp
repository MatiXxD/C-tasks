#include <stdio.h>

int main() {
	
	int days;
	float loan;
	float percents;
	float stdLoan = -1337;


	printf("%s", "Enter sum of the loan(-1 to stop input): ");
	scanf_s("%f", &loan);

	while (loan != -1) {

		printf("%s", "Enter interest rate: ");
		scanf_s("%f", &percents);

		printf("%s", "Enter term for loan in days: ");
		scanf_s("%d", &days);

		stdLoan = (percents * days * loan) / 365;
		printf("Payment at standard interest: %.2f $\n", stdLoan);
		printf("----------------------------------------------\n\n");

		printf("%s", "Enter sum of the loan(-1 to stop input): ");
		scanf_s("%f", &loan);
	}

	if (stdLoan == -1337)
		puts("\nNothing was entered");

	return 0;
}