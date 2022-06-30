#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void initArray(int* arr, unsigned int size);
void selectionSort(int* arr, unsigned int size);
void printArray(int* arr, unsigned int size);

int main() {

	srand((unsigned int)time(NULL));

	int arr[SIZE];
	initArray(arr, SIZE);

	puts("Array before sort:");
	printArray(arr, SIZE);
	puts("\nArray after sort:");
	selectionSort(arr, SIZE);
	printArray(arr, SIZE);

	return 0;

}

void initArray(int* arr, unsigned int size) {

	for (unsigned int i = 0; i < size; i++)
		arr[i] = 1 + rand() % 10;

}

void selectionSort(int* arr, unsigned int size) {

	for (unsigned int i = 0; i < size - 1; i++)
		for (unsigned int j = i + 1; j < size; j++)
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

}

void printArray(int* arr, unsigned int size) {

	for (int i = 0; i < size; i++) {
		printf("%3d", arr[i]);
		if ((i + 1) % 10 == 0)
			putchar('\n');
	}

}
