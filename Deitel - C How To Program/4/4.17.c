#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

	int id;
	float loan, balance;
	float newLoan;
	int i;

	for (i = 1; i <= 3; i++) {

		printf("%s", "Enter client's id: ");
		scanf_s("%d", &id);
		printf("%s", "Enter client's old loan: ");
		scanf_s("%f", &loan);
		printf("%s", "Enter client's balance to pay: ");
		scanf_s("%f", &balance);

		puts("\n------------------------------------------------------------\n");

		newLoan = loan / 2;
		printf("The new loan for %d client is %.2f\n", i, newLoan);

		if (newLoan < balance)
			puts("Loan limit was reached!");

		puts("\n\n\n");

	}

	return 0;

}