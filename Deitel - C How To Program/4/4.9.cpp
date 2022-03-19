#include <stdio.h>

int main() {

	int count;
	int i;
	int number;
	int sum = 0;

	puts("Enter number of sequence");
	scanf_s("%d", &count);
	
	for (i = count; i > 0; i--) {
		
		scanf_s("%d", &number);
		sum += number;

	}

	printf("The sum of %d numbers is %d", count, sum);

	return 0;

}