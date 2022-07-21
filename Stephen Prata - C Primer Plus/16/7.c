#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void showArray(const double arr[], int n);
double* newDoubleArray(int n, ...);

int main(void) {

	double* p1;
	double* p2;

	p1 = newDoubleArray(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	p2 = newDoubleArray(4, 100.0, 20.00, 8.08, -1890.0);

	puts("First array:");
	showArray(p1, 5);
	puts("\nSecond array:");
	showArray(p2, 4);

	free(p1);
	free(p2);

	return 0;

}


void showArray(const double arr[], int n) {

	for (int i = 0; i < n; i++)
		printf("%12.2lf ", arr[i]);
	putchar('\n');

}

double* newDoubleArray(int n, ...) {

	int ind = 0;
	double* array = (double*)malloc(n * sizeof(double));
	va_list args;

	va_start(args, n);
	for (int i = 0; i < n; i++)
		array[ind++] = va_arg(args, double);
	va_end(args);

	return array;

}
