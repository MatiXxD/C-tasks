#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num1, num2;

	puts("Enter two integer numbers");

	scanf("%d%d", &num1, &num2);

	if (num1 % num2) 
		puts("The first number isn't a multiple of the second");
	
	if (!(num1 % num2))
		puts("The first number is a multiple of the second");

	return 0;
}