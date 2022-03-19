#include <stdio.h>
#define SIZE 20

int main(void) {

	int i, j;
	int value;
	int arr[SIZE] = { 0 };

	puts("Enter 20 numbers between 10 and 100");

	for (i = 0; i <= SIZE - 1; i++) {

		scanf_s("%d", &value);
		arr[i] = value;

		for (j = 0; j < i; j++)
			if (arr[i] == arr[j])
				arr[i] = 0;

	}

	printf("Unique numbers are:  ");
	for (i = 0; i < SIZE; i++)
		if (arr[i])
			printf("%d  ", arr[i]);

	return 0;

}