#include <stdio.h>

int main() {

	int number;
	int controlNum = 9999;
	int i = 0;
	int total = 0;

	puts("Enter number (9999 to stop)");
	scanf_s("%d", &number);

	while (number != 9999) {

		total += number;

		puts("Enter number (9999 to stop)");
		scanf_s("%d", &number);
		i++;

	}

	if (i == 0)
		puts("Nothing was entered");
	else
		printf("Average number is %d", total / i);

	return 0;

}