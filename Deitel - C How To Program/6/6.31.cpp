#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 12

int countOfDignits(int arr[]);
void fillArr(int arr[]);
void bucketSort(int arr[]);
void fillBuckets(const int arr[], int buckets[][SIZE], int rank);
void getFromBuckets(int arr[], int buckets[][SIZE]);
void clearBuckets(int buckets[][SIZE]);

int main(void) {

	int i;
	int arr[SIZE] = { 0 };

	srand((int)time(NULL));
	fillArr(arr);

	puts("Unsorted array is:\n");
	for (i = 0; i < SIZE; i++)
		printf("%-5d", arr[i]);

	bucketSort(arr);
	puts("\n\n\nSorted array is:\n");
	for (i = 0; i < SIZE; i++)
		printf("%-5d", arr[i]);

	puts("\n\n");

	return 0;

}

int countOfDignits(int arr[]) {

	int i;
	int dignits = 1;
	int divider = 10;
	int largest = arr[0];

	for (i = 1; i < SIZE; i++)
		if (arr[i] > largest)
			largest = arr[i];

	while (largest / divider > 0) {

		dignits++;
		divider *= 10;

	}

	return dignits;

}

void bucketSort(int arr[]) {

	int i;
	int buckets[10][SIZE] = { 0 };
	
	for (i = 1; i <= countOfDignits(arr); i++) {

		fillBuckets(arr, buckets, i);
		getFromBuckets(arr, buckets);

		clearBuckets(buckets);

	}


}

void fillBuckets(const int arr[], int buckets[][SIZE], int rank) {

	int i;
	int dignit, divider2, numInBucket;
	int divider1 = 1;

	while (rank--)
		divider1 *= 10;
	divider2 = divider1 / 10;

	for (i = 0; i < SIZE; i++) {

		dignit = (arr[i] % divider1 - arr[i] % divider2) / divider2;

		numInBucket = ++buckets[dignit][0];
		buckets[dignit][numInBucket] = arr[i];

	}

}

void getFromBuckets(int arr[], int buckets[][SIZE]) {

	int i, j;
	int k = 0;

	for (i = 0; i < 10; i++)
		for (j = 1; j <= buckets[i][0]; j++)
			arr[k++] = buckets[i][j];

}

void clearBuckets(int buckets[][SIZE]) {

	int i, j;

	for (i = 0; i < 10; i++)
		for (j = 0; j < SIZE; j++)
			buckets[i][j] = 0;

}

void fillArr(int arr[]) {

	int i, num;

	for (i = 0; i < SIZE; i++) {

		num = rand() % 10000;
		arr[i] = num;

	}

}