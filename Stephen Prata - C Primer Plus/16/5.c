#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

#define SIZE 50


void fillArray(int arr[], int size);
void printArray(const int arr[], int size);
bool inArray(const int arr[], int maxInd, int ind);
void takeRandVal(int arr[], int size, int n);


int main(void) {

	int array[SIZE];

	srand((unsigned int)time(NULL));
	fillArray(array, SIZE);
	printArray(array, SIZE);
	takeRandVal(array, SIZE, 20);

	return 0;

}


void fillArray(int arr[], int size) {

	for (int i = 0; i < size; i++)
		arr[i] = rand() & 0xFF;

}

void printArray(const int arr[], int size) {

	for (int i = 1; i <= size; i++) {
		printf("%4d", arr[i-1]);
		if (!(i % 10)) putchar('\n');
	}
	putchar('\n');

}

bool inArray(const int arr[], int maxInd, int ind) {

	for (int i = 0; i < maxInd; i++)
		if (arr[i] == ind) return true;

	return false;

}

void takeRandVal(int arr[], int size, int n) {

	int ind = 0;
	int* indexArray = (int*)malloc(n * sizeof(int));

	assert(size >= n);

	puts("Picked numbers:");
	for (int i = 0; i < n; i++) {
		int temp = rand() % n;
		if (inArray(indexArray, ind, temp)) continue;
		indexArray[ind++] = temp;
		printf("%d\n", arr[temp]);
	}

}
