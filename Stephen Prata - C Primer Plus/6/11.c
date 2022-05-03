#include <stdio.h>


int main(void) {

	const int SIZE = 8;
	int arr[SIZE];

	printf("Fill array with %d integer numbers.\n", SIZE);
	for (int i = 0; i < SIZE; i++)
		scanf_s("%d", &arr[i]);

	printf("Reversed array:\n");
	for (int i = SIZE - 1; i >= 0; i--)
		printf("%d ", arr[i]);
	puts("");

	return 0;

}
