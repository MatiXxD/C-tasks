#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int num1, num2;

	puts("Enter two integer numbers");

	scanf("%d%d", &num1, &num2);

	if (num1 > num2) {
		printf("%d is larger than %d\n", num1, num2);
	}

	if (num1 < num2) {
		printf("%d is larger than %d\n", num2, num1);
	}

	if (num1 == num2) {
		printf("%d is equal to %d\n", num1, num2);
	}

	return 0;
}