#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char symb;

	puts("Enter one symbol");

	scanf("%c", &symb);

	printf("Number for %c is %d\n", symb, symb);

	return 0;
}