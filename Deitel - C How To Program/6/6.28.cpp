#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

bool check(int arr[], int num);
void printArray(int arr[]);

int main(void) {

	int i;
	int num;
	int arr[SIZE] = { 0 };

	srand((int)time(NULL));

	for (i = 1; i <= SIZE; i++) {

		num = 1 + rand() % 20;

		while (check(arr, num))
			num = 1 + rand() % 20;

	}

	printArray(arr);

	return 0;

}

bool check(int arr[], int num) {

	int i;

	for (i = 0; i < SIZE; i++) 
		if (arr[i] == num)
			return true;
	
	for (i = 0; i < SIZE; i++)
		if (arr[i] == 0) {

			arr[i] = num;

			return false;

		}


}

void printArray(int arr[]) {

	int i;

	for (i = 0; i < SIZE; i++) {

		printf("%3d", arr[i]);

		if (i == 9)
			puts("");

	}

}