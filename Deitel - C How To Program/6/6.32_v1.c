#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void fillArr(int arr[]);
void selectionSort(int arr[], int size);
void printArr(int arr[]);

int main(void) {

	srand(time(NULL));

	int arr[SIZE];
	fillArr(arr);

	puts("Unsorted array is \n");
	printArr(arr);

	selectionSort(arr, 1);

	puts("\n\nSorted array is \n");
	printArr(arr);


	return 0;

}

void fillArr(int arr[]) {
	
	int i;

	for (i = 0; i < SIZE; i++)
		arr[i] = 1 + rand() % 1000;

}

void selectionSort(int arr[], int pos) {

	int i, temp;
	int j = 1337;
	int min = arr[pos - 1];

	if (pos != 20) {

		for (i = pos; i < SIZE; i++)
			if (arr[i] < min) {

				min = arr[i];
				j = i;

			}
		
		if (j != 1337) {

			temp = arr[pos - 1];
			arr[pos - 1] = min;
			arr[j] = temp;

		}

		return selectionSort(arr, pos + 1);
		
	}

	else
		return;
}

void printArr(int arr[]) {

	int i;

	for (i = 0; i < SIZE; i++) {

		printf("%-5d", arr[i]);

		if (!((i + 1) % 10))
			puts("");

	}

}