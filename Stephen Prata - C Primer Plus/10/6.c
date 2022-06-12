#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArr(double arr[], unsigned size);
void reverseArr(double arr[], double newArr[], unsigned size);

int main(void) {

	double arr[SIZE];
	double newArr[SIZE];

	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; i++)
		arr[i] = 1 + rand() % 10 + (double)(rand() % 10) / 10 + (double)(rand() % 10) / 100;

	printf("Array:\n");
	printArr(arr, SIZE);
	reverseArr(arr, newArr, SIZE);
	printf("Revesed array:\n");
	printArr(newArr, SIZE);

	return 0;

}

void printArr(double arr[], unsigned size) {

	for (unsigned i = 0; i < size; i++)
		printf("%.2lf ", arr[i]);
	putchar('\n');

}

void reverseArr(double arr[], double newArr[], unsigned size) {

	for (int i = size - 1; i >= 0; i--)
		newArr[size - i - 1] = arr[i];

}
