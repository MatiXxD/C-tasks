#include <stdio.h>

void printArr(int arr[], const int SIZE);

int main(void) {

	const int SIZE = 8;
	int arr[SIZE];
	int sumArr[SIZE];
	int currentSum = 0;

	printf("Fill first array with integer numbers: ");
	for (int i = 0 ; i < SIZE ; i++)
		scanf_s("%d", &arr[i]);

	for (int i = 0; i < SIZE; i++) {

		currentSum += arr[i];
		sumArr[i] = currentSum;

	}

	printf("Print arrays:\n");
	printArr(arr, SIZE);
	printArr(sumArr, SIZE);

	return 0;

}

void printArr(int arr[], const int SIZE) {

	for (int i = 0; i < SIZE; i++)
		printf("%4d", arr[i]);
	puts("");

}
