#include <stdio.h>

int main() {
	
	int x, y;
	int result;
	int count = 1;

	printf("Enter the number and its power\n");
	scanf_s("%d%d", &x, &y);

	result = 1;

	while (count <= y) {
		result *= x;
		count++;
	}

	printf("%d in %d power is %d", x, y, result);

	return 0;
}