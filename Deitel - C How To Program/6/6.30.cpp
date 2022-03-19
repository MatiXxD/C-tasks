#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void deletInArr(int arr[], int num);
void printSimpleNums(int arr[]);

int main(void) {

	int i, j;

	int arr[SIZE] = { 0 };
	for (i = 0; i < SIZE; i++)
		arr[i] = 1;

	
	for (j = 2; j < SIZE; j++)
		deletInArr(arr, j);

	printSimpleNums(arr);

	return 0;

}

void deletInArr(int arr[], int num) {

	int i;

	for (i = num + 1; i < SIZE; i++)
		if (!(i % num))
			arr[i] = 0;

}

void printSimpleNums(int arr[]) {

	int i;
	int countOfSimple = 0;
	int count = 0;

	for(i = 2; i < SIZE; i++)
		if (arr[i]) {

			printf("%5d", i);
			count++;
			countOfSimple++;

			if (!(count % 5))
				puts("");

		}

	printf("\n\nFound %d simple numbers.", countOfSimple);

}