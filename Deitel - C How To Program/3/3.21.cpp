#include <stdio.h>

int main() {
	
	int hours;
	float rate;
	float salary = -1337;
	
	printf("%s", "Enter the number of spent hours(input -1 to stop): ");
	scanf_s("%d", &hours);

	while (hours != -1) {

		printf("%s", "Enter hourly rate for this employee: ");
		scanf_s("%f", &rate);

		if (hours <= 40){
			salary = hours * rate;
			printf("Salary: %.2f", salary);
		}

		else {
			salary = 40 * rate + (hours - 40.0) * rate * 1.5;
			printf("Salary: %.2f", salary);
		}
		puts("\n-----------------------------------------------------------\n");

		printf("%s", "Enter the number of spent hours(input -1 to stop): ");
		scanf_s("%d", &hours);
	}

	if (salary == -1337)
		puts("\nNothing was entered");

	return 0;
}