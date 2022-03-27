#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int minInArr(int arr[], int pos, int min);

int main(void) {

	int i;
	int arr[SIZE];

	srand((int)time(NULL));
	for (i = 0; i < SIZE; i++)
		arr[i] = 1 + rand() % 100;

	puts("------------------Array------------------");
	for (i = 0; i < SIZE; i++) {

		printf("%-4d", arr[i]);

		if (!((i + 1) % 10))
			puts("");

	}

	printf("\n\nMin element is %d", minInArr(arr, 0, arr[0]));

	return 0;

}

int minInArr(int arr[], int pos, int min) {
	
	if (pos > SIZE - 1)
		return min;

	if (arr[pos] < min)
		minInArr(arr, ++pos, arr[pos - 1]);

	else
		minInArr(arr, ++pos, min);

}