#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void printArr(int arr[], int size);
void sumArr(int sum[], int arr1[], int arr2[], int size);

int main(void) {

	int arr1[SIZE] = { 2, 4, 6, 8, 10 };
	int arr2[SIZE] = { 1, 2, 3, 4, 5 };
	int sum[SIZE];

	printf("Sum array is:\n");
	sumArr(sum, arr1, arr2, SIZE);
	printArr(sum, SIZE);

	return 0;

}

void printArr(int arr[], int size) {

	for (int i = 0; i < size; i++)
		printf("%5d", arr[i]);
	putchar('\n');

}

void sumArr(int sum[], int arr1[], int arr2[], int size) {

	for (int i = 0; i < size; i++)
		sum[i] = arr1[i] + arr2[i];

}
