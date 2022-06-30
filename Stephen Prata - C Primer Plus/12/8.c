#include <stdio.h>
#include <stdlib.h>

int* make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void){

	int* pa;
	int size;
	int value;

	printf("Enter the number of elements: ");
	while (scanf("%d", &size) == 1 && size > 0){
		printf("Enter value to initialize: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa){
			show_array(pa, size);
			free(pa);
		}
		printf("\nEnter number of items (<1 to exit): ");
	}
	printf("Program completed.\n");

	return 0;

}

int* make_array(int elem, int val) {

	int* arr = (int*)malloc(elem * sizeof(int));
	if (arr) {
		for (int i = 0; i < elem; i++)
			arr[i] = val;
	}
	else
		puts("Memory wasn't allocated");

	return arr;

}

void show_array(const int ar[], int n) {

	int i;
	for (i = 0; i < n; i++)
		printf("%d%c", ar[i], (i + 1) % 8 ? ' ' : '\n');
	if (i % 8)
		putchar('\n');

}
