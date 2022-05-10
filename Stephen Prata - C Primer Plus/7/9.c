#include <stdio.h>
#include <stdbool.h>

bool isSimple(int num);

int main(void) {

	int num;

	printf("Enter number: ");
	scanf_s("%d", &num);
	for (int i = 2; i <= num; i++)
		if (isSimple(i))
			printf("Number %d is simple.\n", i);

	return 0;

}

bool isSimple(int num) {

	for (int i = 2; i * i <= num; i++)
		if (!(num % i))
			return false;

	return true;

}
