#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

#define SIZE 10

void printArr(double arr[], unsigned size);
unsigned maxIndex(double* arr, unsigned size);

int main(void) {

	double arr[SIZE];

	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; i++)
		arr[i] = 1 + rand() % 10 + (double)(rand() % 10) / 10 + (double)(rand() % 10) / 100;

	printf("For array:\n");
	printArr(arr, SIZE);
	printf("Max index is %u\n", maxIndex(arr, SIZE));

	return 0;

}

void printArr(double arr[], unsigned size) {

	for (unsigned i = 0; i < size; i++)
		printf("%.2lf ", arr[i]);
	putchar('\n');

}

unsigned maxIndex(double* arr, unsigned size) {

	double max = DBL_MIN;
	unsigned index = 0;

	for (unsigned i = 0; i < size; i++)
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}

	return index;

}
