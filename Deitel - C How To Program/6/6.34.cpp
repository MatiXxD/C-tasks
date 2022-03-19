#include <stdio.h>

#define SIZE 100

int linearSearch(int arr[], int pos, int key);

int main(void) {

	int i;
	int pos;
	int key;
	int arr[SIZE] = { 0 };

	for (i = 0; i < SIZE; i++)
		arr[i] = 2 * i;

	puts("Enter key to find in array:");
	scanf_s("%d", &key);

	pos = linearSearch(arr, 0, key);
	if (pos != -1)
		printf("Key %d was found in arr[%d]!", key, pos);

	else 
		printf("Key %d wasn't found!", key);


	return 0;

}

int linearSearch(int arr[], int pos, int key) {

	if (arr[pos] == key)
		return pos;

	else if (pos > SIZE - 1)
		return -1;

	else
		return linearSearch(arr, pos + 1, key);


}