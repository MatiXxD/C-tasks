#include <stdio.h>
#define SIZE 11

void output(int sort[]);

int main(void) {

	float soldItems, salary;
	int employeeID = 1;

	int sort[SIZE] = {0};
	
	printf("Enter %d employee sales (-1 to stop input) : ", employeeID);
	scanf_s("%f", &soldItems);

	while (soldItems != -1) {

		salary = 200.0f + 0.09f * soldItems;
		printf("Salary of %d employee is %.2f\n\n", employeeID, salary);

		if (salary >= 200 && salary < 1000)
			++sort[(int)salary / 100];

		else
			++sort[10];

		printf("Enter %d employee sales (-1 to stop input) : ", employeeID);
		scanf_s("%f", &soldItems);

	}

	output(sort);

	return 0;

}

void output(int sort[]) {

	printf("\nEmployees in the range:\n");
	printf("$200-$299 : %d\n", sort[2]);
	printf("$300-$399 : %d\n", sort[3]);
	printf("$400-$499 : %d\n", sort[4]);
	printf("$500-$599 : %d\n", sort[5]);
	printf("$600-$699 : %d\n", sort[6]);
	printf("$700-$799 : %d\n", sort[7]);
	printf("$800-$899 : %d\n", sort[8]);
	printf("$900-$999 : %d\n", sort[9]);
	printf("$1000 and more : %d\n", sort[10]);
}