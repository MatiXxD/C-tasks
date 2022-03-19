#include <stdio.h>
#include <limits.h>

int main() {

	int number;
	int count;
	int min = INT_MAX;
	int i;

	puts("Enter count of numbers");
	scanf_s("%d", &count);

	for (i = 1; i <= count; i++) {

		scanf_s("%d", &number);

		if (number < min)
			min = number;

	}

	printf("The smallest of these number is %d", min);

	return 0;

}