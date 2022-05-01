#include <stdio.h>


int main(void) {

	int n;

	printf("Enter number: ");
	scanf_s("%d", &n);

	int i = 0;
	while (i <= 10)
		printf("%d ", n + i++);

	return 0;

}
