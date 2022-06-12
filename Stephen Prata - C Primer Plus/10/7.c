#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void printArr(double arr[], unsigned size);
void copy_arr(double arr[], double source[], double size);

int main(void) {

	double startArr[ROWS][COLS] = {
		{1.1, 2.2, 3.3, 4.4, 5.5},
		{6.6, 7.7, 8.8, 9.9, 10.1},
		{11.2, 12.3, 13.4, 14.5, 15.6},
		{16.7, 17.8, 18.9, 19.1, 20.2},
		{21.3, 22.4, 23.5, 24.6, 25.7}
	};
	double copyOfArr[ROWS][COLS];

	for (int i = 0; i < ROWS; i++)
		copy_arr(copyOfArr[i], startArr[i], COLS);

	printf("Copy of array is:\n");
	for (int i = 0; i < ROWS; i++)
		printArr(copyOfArr[i], COLS);


	return 0;

}

void printArr(double arr[], unsigned size) {

	for (unsigned i = 0; i < size; i++)
		printf("%10.2lf ", arr[i]);
	putchar('\n');

}

void copy_arr(double arr[], double source[], double size) {

	for (int i = 0; i < size; i++)
		arr[i] = source[i];

}
