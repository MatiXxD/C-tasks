#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 7

void printArr(double arr[], unsigned size);
void copy_arr(double arr[], double source[], double size);

int main(void) {

	double arr[SIZE];
	double newArr[3];

	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; i++)
		arr[i] = 1 + rand() % 10 + (double)(rand() % 10) / 10 + (double)(rand() % 10) / 100;

	printf("Start array is:\n");
	printArr(arr, SIZE);
	copy_arr(newArr, arr + 2, 3);
	printf("In new array we have elements:\n");
	printArr(newArr, 3);

	return 0;

}

void printArr(double arr[], unsigned size) {

	for (unsigned i = 0; i < size; i++)
		printf("%.2lf ", arr[i]);
	putchar('\n');

}

void copy_arr(double arr[], double source[], double size) {

	for (int i = 0; i < size; i++)
		arr[i] = source[i];

}
