#include <stdio.h>
#include <stdlib.h>


void printArr(int arr[], const unsigned size);


int main() {

    int size;
    int* arr;

    printf("Enter size of array: ");
    scanf_s("%d", &size);
    arr = (int*)calloc(size, sizeof(int));

    if (arr != NULL) {

        printf("Enter your array: ");
        for (int i = 0; i < size; i++)
            scanf_s("%d", &arr[i]);


        printf("Your array is:\n");
        printArr(arr, size);

        size /= 2;
        arr = (int*)realloc(arr, size * sizeof(int));
        printf("Now array is:\n");
        printArr(arr, size);

    }

    return 0;

}


void printArr(int arr[], const unsigned size) {

    for (int i = 0; i < size; i++)
        printf("%d%c", arr[i], (i + 1) % 10 ? ' ' : '\n');
    putchar('\n');

}
