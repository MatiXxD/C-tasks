#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void printArr(int arr[], int size, int pos, int enter);

int main(void) {

	int i;
	int arr[SIZE];

	srand((int)time(NULL));

	for (i = 0; i < SIZE; i++)
		arr[i] = 1 + rand() % 100;

	printArr(arr, SIZE, 0, 0);

	return 0;

}

void printArr(int arr[], int size, int pos, int enter) {

	enter++;

	if (size) {

		printf("%-4d", arr[pos]);

		if (enter == 10) {

			puts("");
			enter = 0;

		}
			

		printArr(arr, --size, ++pos, enter);

	}

	else
		return;

}
