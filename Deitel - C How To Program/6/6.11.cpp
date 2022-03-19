#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

void inputArray(int a[], int size);

void bubleSort(int a[], int size);

void printArray(int a[], int size);

int main(void) {

	int a[SIZE];

	srand((int)time(NULL));
	inputArray(a, SIZE);

	printArray(a, SIZE);
	bubleSort(a, SIZE);
	printArray(a, SIZE);

	return 0;

}

void inputArray(int a[], int size) {
	
	int i;

	for (i = 0; i < size; i++) 
		a[i] = 1 + rand() % 100;

}

void bubleSort(int a[], int size) {

	int i, j, k, temp;

	for (i = 1; i < size; i++) {
		
		k = 0;

		for (j = 0; j < size - i; j++) {

			if (a[j] > a[j + 1]) {

				k = 1;

				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;

			}

		}
		
		if (!k)
			i = 228;

	}
		

}

void printArray(int a[], int size) {

	int i;

	puts("Array is:");
	for (i = 0; i < size ; i++) {

		if (i % 10 == 0)
			puts("");

		printf("%d  ", a[i]);

	}

	puts("\n-------------------------------------\n");

}