#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 50


void initArray(double arr[], int size);
void transform(const double source[], double target[], int size, double (*fp)(double));
void printArray(double arr[], int size);
double pow2(double num);


int main(void) {

	double source[SIZE];
	double target[SIZE];

	initArray(source, SIZE);
	transform(source, target, SIZE, pow2);

	puts("Source array is:");
	printArray(source, SIZE);
	puts("After tranform array is:");
	printArray(target, SIZE);

	return 0;

}


void initArray(double arr[], int size) {

	for(int i = 0 ; i < size ; i++)
		arr[i] = 100.0 - (double)(rand() % 200) + (double)(rand() % 100) / 100;

}

void transform(const double source[], double target[], int size, double (*fp)(double)) {

	for (int i = 0; i < size; i++)
		target[i] = (*fp)(source[i]);

}

void printArray(double arr[], int size) {

	int i;
	for (i = 0; i < size; i++) {
		printf("%10.2lf", arr[i]);
		if (!((i + 1) % 10)) putchar('\n');
	}
	if (i % 10) putchar('\n');

}

double pow2(double num) {

	return num * num;

}
