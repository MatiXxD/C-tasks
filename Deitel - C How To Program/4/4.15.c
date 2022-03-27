#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

	double amount;
	double principal = 1000.0;
	double rate;
	unsigned int year;

	printf("%4s%21s\n", "Year", "Amount on deposit");

	for (rate = 5; rate <= 10; rate++) {

		printf("For %.2f rate\n", rate / 100);

		for (year = 1; year <= 10; year++) {

			amount = principal * pow(1.0 + rate / 100, year);
			printf("%4d%21.2f\n", year, amount);

		}

		puts("-----------------------------------------------------------");
	}
	

	return 0;

}