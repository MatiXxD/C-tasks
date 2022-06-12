#include <stdio.h>
#include <float.h>

void fill2DArray(int rows, int cols, double arr[rows][cols]);
void print2DArray(int rows, int cols, double arr[rows][cols]);
double avgOfArray(double arr[], int size);
double avgOf2DArray(int rows, int cols, double arr[rows][cols]);
double maxOf2DArray(int rows, int cols, double arr[rows][cols]);

int main(void) {

	int rows = 3;
	int cols = 5;

	double arr[rows][cols];

	fill2DArray(rows, cols, arr);
	print2DArray(rows, cols, arr);

	for (int i = 0; i < rows; i++)
		printf("Avg of %d set is %.2f\n", i+1, avgOfArray(*(arr + i), cols));
	putchar('\n');

	printf("Avg of 2D array is %.2f\n", avgOf2DArray(rows, cols, arr));
	printf("Max of 2D array is %.2f\n", maxOf2DArray(rows, cols, arr));

	return 0;

}

void fill2DArray(int rows, int cols, double arr[rows][cols]) {

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

void print2DArray(int rows, int cols, double arr[rows][cols]) {

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

double avgOf2DArray(int rows, int cols, double arr[rows][cols]) {

	double total = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			total += arr[i][j];

	return total / (rows * cols);

}

double maxOf2DArray(int rows, int cols, double arr[rows][cols]) {

	double max = DBL_MIN;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (arr[i][j] > max) max = arr[i][j];

	return max;

}
