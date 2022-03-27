#include <stdio.h>

int main() {

	int i;
	int i2;

	puts("Enter integer number");
	scanf_s("%d", &i);
	i2 = i;

	puts("For predecrement:");

	printf("1)%d\n", --i);
	printf("2)%d\n\n", i);

	i = i2;

	puts("For postdecrement:");

	printf("1)%d\n", i--);
	printf("2)%d\n\n", i);

	return 0;
}