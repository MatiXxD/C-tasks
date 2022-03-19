#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num1;
	int num2;
	int res1, res2, res3, res4, res5;

	puts("Enter two integer numbers");

	scanf("%d %d", &num1, &num2);

	res1 = num1 + num2;
	res2 = num1 - num2;
	res3 = num1 * num2;
	res4 = num1 / num2;
	res5 = num1 % num2;

	printf("%d + %d = %d\n", num1, num2, res1);
	printf("%d - %d = %d\n", num1, num2, res2);
	printf("%d * %d = %d\n", num1, num2, res3);
	printf("%d / %d = %d\n", num1, num2, res4);
	printf("%d mod %d = %d\n", num1, num2, res5);

	return 0;
}
