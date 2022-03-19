#include <stdio.h>

int main() {
	
	float basicSalary;
	float soldAmount;
	float resultSalary = -1337;

	puts("Enter basic salary");
	scanf_s("%f", &basicSalary);

	printf("%s", "Enter sales amount(-1 to stop input): ");
	scanf_s("%f", &soldAmount);

	while (soldAmount != -1) {

		resultSalary = soldAmount * 0.09 + basicSalary;
		printf("Salary is %.2f\n", resultSalary);
		puts("-----------------------------------------------");

		printf("%s", "Enter sales amount(-1 to stop input): ");
		scanf_s("%f", &soldAmount);
	}

	if (resultSalary == -1337)
		puts("Nothing was entered");

	return 0;
}