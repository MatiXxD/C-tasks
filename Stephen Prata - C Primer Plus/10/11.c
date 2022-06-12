#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 5

void printArr(int arr[][COLS], int rows, int cols);
void dublArr(int arr[][COLS], int rows, int cols);

int main(void) {

	int arr[ROWS][COLS] = {
		{1, 2, 3, 4, 5},
		{2, 4, 6, 8, 10},
		{3, 6, 9, 12, 15}
	};

	printf("Start array is:\n");
	printArr(arr, ROWS, COLS);
	dublArr(arr, ROWS, COLS);
	printf("Doubled array is:\n");
	printArr(arr, ROWS, COLS);

	return 0;

}

void printArr(int arr[][COLS], int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%5d", arr[i][j]);
		putchar('\n');
	}

}

void dublArr(int arr[][COLS], int rows, int cols) {

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] *= 2;

}
