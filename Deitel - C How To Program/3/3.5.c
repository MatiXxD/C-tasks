#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int num = 1;
	int sum = 0;

	while (num <= 10)
		sum += num++;

	printf("The sum of the first 10 number is %d\n", sum);

	return 0;
}