#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num;
	int odd, even;

	puts("Enter integer number");

	scanf("%d", &num);

	if (num % 2)
		puts("Number is odd");

	if (!(num % 2))
		puts("Number is even");

	return 0;
}