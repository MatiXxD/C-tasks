#include <stdio.h>

int main(void) {

	const int SIZE = 8;
	int arr[SIZE];
	int i, j, pow;

	for (i = 0, pow = 2; i < SIZE; i++, pow *= 2)
		arr[i] = pow;

	j = 0;
	printf("Array is:\n");
	do {

		printf("%d ", arr[j++]);

	} while (j < SIZE);

	return 0;

}
