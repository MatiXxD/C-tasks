#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

	int id;
	int hours;
	int soldItms;
	float salary, hourSalary, stdSalary, weekSales, percent, itmPrice;

	printf("%s", "Enter your id (0 to stop input): ");
	scanf_s("%d", &id);

	while (id) {

		switch (id) {

		case 1:
			printf("%s", "Enter your week salary: ");
			scanf_s("%f", &salary);
			printf("Your week salary is %.2f $\n", salary);
			break;

		case 2:
			printf("%s", "Enter number of hours you worked and salary per hour: ");
			scanf_s("%d %f", &hours, &hourSalary);
			salary = hours > 40 ?
				(hourSalary * 40.0f + (hours - 40.0f) * 1.5f * hourSalary) :
				(hourSalary * hours);
			printf("Your week salary is %.2f $\n", salary);
			break;

		case 3:
			printf("%s", "Enter your standart salary, weekly sales and percent (in %) you get: ");
			scanf_s("%f%f%f", &stdSalary, &weekSales, &percent);
			printf("Your week salary is %.2f $\n", (double)stdSalary + weekSales * percent / 100);
			break;

		case 4:
			printf("%s", "Enter amout of the sold items: ");
			scanf_s("%d", &soldItms);
			printf("%s", "Enter price of one item: ");
			scanf_s("%f", &itmPrice);
			printf("Your week salary is %.2f $\n", (double)soldItms * itmPrice);
			break;

		default:
			printf("You entered wrong id. Chose again FROM 1 TO 4\n");
			break;

		}

		puts("\n---------------------------------------------------------------------------\n");

		printf("%s", "Enter your id (0 to stop input): ");
		scanf_s("%d", &id);
	}

	return 0;

}