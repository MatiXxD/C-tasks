// Compile with gcc
// Doesn't compile in VS in my case

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 5

void copyArrStd(int rows, int cols, double newArrPtr[rows][cols], double sourcePtr[rows][cols]);
void print2Darr(int rows, int cols, double arr[rows][cols]);

int main(void) {

	double arr[ROWS][COLS] = {
		{1.1, 2.2, 3.3, 4.4, 5.5},
		{10.1, 20.2, 30.3, 40.4, 50.5},
		{100.1, 200.2, 300.3, 400.4, 500.5}
	};

	int rows = ROWS;
	int cols = COLS;
	double newArr[rows][cols];

	printf("Copy of array is:\n");
	copyArrStd(rows, cols, newArr, arr);
	print2Darr(rows, cols, newArr);

	return 0;

}

void copyArrStd(int rows, int cols, double newArrPtr[rows][cols], double sourcePtr[rows][cols]) {

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			newArrPtr[i][j] = sourcePtr[i][j];

}

void print2Darr(int rows, int cols, double arr[rows][cols]) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%10.2lf", arr[i][j]);
		putchar('\n');
	}

}
