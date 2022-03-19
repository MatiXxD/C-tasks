#include <stdio.h>

int main() {

	int num;
	int max2 = 0;
	int max1 = 0;
	int counter = 1;

	while (counter <= 10) {

		puts("Enter positive number");
		scanf_s("%d", &num);

		if (num > max1) {

			max2 = max1;
			max1 = num;

		}

		else if (num > max2)
			max2 = num;

		counter++;

	}

	printf("The largest numbers are %d an %d", max1, max2);

	return 0;
}