#include <stdio.h>

#define SIZE 15

void printHeader(void);
int binarySearch(int arr[], int a, int b, int key);
void printRow(int arr[], int low, int mid, int high);

int main(void) {

	int key, i, result;
	int arr[SIZE];

	for (i = 0; i < SIZE; i++)
		arr[i] = 2 * i;

	printf("Enter a number between 0 and 28: ");
	scanf_s("%d", &key);
	
	printHeader();
	result = binarySearch(arr, 0, SIZE - 1, key);

	if(result != -1)
		printf("\n%d found in array element %d\n", key, result);

	else
		printf("\n%d not found\n", key);

	return 0;

}

void printHeader(void) {

	int i;

	printf("\nSubscripts:\n");

	for (i = 0; i < SIZE; i++)
		printf("%3d ", i);

	puts("");

	for (i = 1; i <= 4 * SIZE; i++)
		printf("-");

	puts("");


}

int binarySearch(int arr[], int a, int b, int key) {

	if (a < b) {

		int mid = (b + a) / 2;
		printRow(arr, a, mid, b);

		if (arr[mid] == key)
			return mid;

		else if (arr[mid] > key)
			return binarySearch(arr, a, mid - 1, key);

		else if (arr[mid] < key)
			return binarySearch(arr, mid + 1, b, key);

	}

	return -1;

}
 
void printRow(int arr[], int low, int mid, int high) {

	int i;

	for (i = 0; i < SIZE; i++) {

		if (i < low || i > high)
			printf("    ");

		else if (i == mid)
			printf("%3d*", arr[i]);

		else
			printf("%3d ", arr[i]);

	}

	puts("");

}