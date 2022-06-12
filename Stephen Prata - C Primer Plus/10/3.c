#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArr(int arr[], unsigned size);
int maxElemInArr(int arr[], unsigned size);

int main(void) {

	int arr[SIZE];

	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; i++)
		arr[i] = 1 + rand() % 10;

	printf("For array:\n");
	printArr(arr, SIZE);
	printf("Max number is %d\n", maxElemInArr(arr, SIZE));

	return 0;

}

void printArr(int arr[], unsigned size) {

	for (unsigned i = 0; i < size; i++)
		printf("%d ", arr[i]);
	putchar('\n');

}

int maxElemInArr(int arr[], unsigned size) {

	int max = INT_MIN;

	for (int i = 0; i < size; i++)
		if (arr[i] > max) max = arr[i];

	return max;

}
