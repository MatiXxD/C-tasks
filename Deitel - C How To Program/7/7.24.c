#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

void printArr(int *arr);
void quickSort(int* const arr, int start, int end);
int partition(int start, int end, int* const arr);
void swap(int i, int j, int* arr);

int main(void) {

	int arr[SIZE] = { 37, 2,  6, 4, 89, 8, 10, 12, 68, 45 };

	printArr(arr);
	quickSort(arr, 0, SIZE - 1);
	printArr(arr);

	return 0;

}

void printArr(int* arr) {

	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);

	puts("\n");

}

void quickSort(int* const arr, int start, int end) {

	int pos;

	if (start < end) {

		pos = partition(start, end, arr);
		quickSort(arr, start, pos - 1);
		quickSort(arr, pos + 1, end);

	}

	else
		return;

}

int partition(int start, int end, int* const arr) {

	int pos = start;
	int left = start + 1;
	int right = end;

	bool flag = 1;
	bool check = 1;

	while (check) {

		bool count = 0;

		if (flag) {

			for(int i = right; i > pos; i--)
				if (arr[pos] > arr[i]) {

					swap(pos, i, arr);

					flag = 0;
					left = pos + 1;
					pos = i;
					count++;

					i = -227;

				}

			if (!count)
				check = 0;

		}

		else {

			for (int i = left; i < pos; i++)
				if (arr[pos] < arr[i]) {

					swap(pos, i, arr);

					flag = 1;
					right = pos - 1;
					pos = i;
					count++;

					i = 227;

				}

			if (!count)
				check = 0;

		}

	}

	return pos;

}

void swap(int i, int j, int* arr) {

	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

}