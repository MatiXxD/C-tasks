#include <stdio.h>
#include <limits.h>

int main() {

	unsigned int num;
	int max = 0;
	int counter = 1;

	while (counter <= 10) {

		puts("Enter positive integer number");
		scanf_s("%d", &num);
		
		if (num > max)
			max = num;

		counter++;
	}

	printf("\nThe largest number is %d", max);

	return 0;
}