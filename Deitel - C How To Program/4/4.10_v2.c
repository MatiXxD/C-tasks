#include <stdio.h>

int main() {

	int number;
	int total = 0;
	int count = 0;

	while (228) {

		puts("Enter number (9999 to stop input)");
		scanf_s("%d", &number);

		if (number == 9999)
			break;

		total += number;
		count++;

	}

	if (count != 0)
		printf("The average of %d numbers is %f\n", count, (float)total / count);

	else
		puts("Nothing was entered");

	return 0;

}