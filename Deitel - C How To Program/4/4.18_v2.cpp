#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

	int tempNum;
	int i;
	int num1, num2, num3, num4, num5;

	puts("You have to enter 5 integer numbers (from 1 to 30)");

	for (i = 1 ; i <= 5 ; i++) {													//Считывание 5 числе 

		printf("Enter %d number: ", i);
		scanf_s("%d", &tempNum);

		if (i == 1)
			num1 = tempNum;

		else if (i == 2)
			num2 = tempNum;

		else if (i == 3)
			num3 = tempNum;

		else if (i == 4)
			num4 = tempNum;

		else 
			num5 = tempNum;

	}

	puts("--------------------------------------------------------");

	printf("1)	");
	while (num1--) 
		printf("*");
	puts("");

	printf("2)	");
	while (num2--)
		printf("*");
	puts("");

	printf("3)	");
	while (num3--)
		printf("*");
	puts("");

	printf("4)	");
	while (num4--)
		printf("*");
	puts("");

	printf("5)	");
	while (num5--)
		printf("*");
	puts("");

	return 0;

}