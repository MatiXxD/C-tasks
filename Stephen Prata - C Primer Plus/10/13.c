#include <stdio.h>
#include <float.h>

#define ROWS 3
#define COLS 5

void fill2DArray(double arr[][COLS], int rows, int cols);
void print2DArray(double arr[][COLS], int rows, int cols);
double avgOfArray(double arr[], int size);
double avgOf2DArray(double arr[][COLS], int rows, int cols);
double maxOf2DArray(double arr[][COLS], int rows, int cols);

int main(void) {

	double arr[ROWS][COLS];

	fill2DArray(arr, ROWS, COLS);
	print2DArray(arr, ROWS, COLS);

	for (int i = 0; i < ROWS; i++)
		printf("Avg of %d set is %.2f\n", i+1, avgOfArray(*(arr + i), COLS));
	putchar('\n');

	printf("Avg of 2D array is %.2f\n", avgOf2DArray(arr, ROWS, COLS));
	printf("Max of 2D array is %.2f\n", maxOf2DArray(arr, ROWS, COLS));

	return 0;

}

void fill2DArray(double arr[][COLS], int rows, int cols) {

	double num;

	for (int i = 0; i < rows; i++) {

		printf("Enter 5 values:\n");
		for (int j = 0; j < cols; j++) {
			scanf_s("%lf", &num);
			arr[i][j] = num;
		}

	}

	putchar('\n');

}

void print2DArray(double arr[][COLS], int rows, int cols) {

	printf("Introduced array:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%-10.2lf", arr[i][j]);
		putchar('\n');
	}

	putchar('\n');

}

double avgOfArray(double arr[], int size) {

	double total = 0;

	for (int i = 0; i < size; i++)
		total += arr[i];

	return total / size;

}

double avgOf2DArray(double arr[][COLS], int rows, int cols) {

	double total = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			total += arr[i][j];

	return total / (rows * cols);

}

double maxOf2DArray(double arr[][COLS], int rows, int cols) {

	double max = DBL_MIN;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (arr[i][j] > max) max = arr[i][j];

	return max;

}
