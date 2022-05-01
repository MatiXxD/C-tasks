#include <stdio.h>


int main(void) {

	int n;
	int count = 0;
	int sum = 0;

	printf("Enter number: ");
	scanf_s("%d", &n);

	while (count++ < n)
		sum += count*count;
	printf("sum = %d\n", sum);

	return 0;

}
