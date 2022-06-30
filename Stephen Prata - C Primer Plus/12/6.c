#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GEN_NUM 1000
#define REPEAT_COUNT 10
#define NUMS_COUNT 10

int* genNums(int numsCount);
void printResults(int* arr, int size);

int main(void) {

	int seedArr[REPEAT_COUNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (int i = 0; i < REPEAT_COUNT; i++) {
		int* temp = genNums(GEN_NUM);
		printResults(temp, NUMS_COUNT);
	}

}

int* genNums(int genNum) {

	static arr[NUMS_COUNT];                                                        // Also can use malloc()
	memset(arr, 0, NUMS_COUNT * sizeof(int));

	for (int i = 0; i < genNum; i++) {
		int temp = rand() % NUMS_COUNT;
		arr[temp]++;
	}

	return arr;

}

void printResults(int* arr, int size) {

	for (int i = 0; i < size; i++)
		printf("Num %d appeared %d times.\n", i + 1, arr[i]);
	putchar('\n');

}
