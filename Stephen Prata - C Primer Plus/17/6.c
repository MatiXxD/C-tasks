#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 100


int cmp(const void* p1, const void* p2);
void fillArray(int array[], int size);
void printArray(int array[], int size);
bool binSearch(int array[], int size, int num);


int main(void) {

    int array[SIZE];
    int searchNum;

    srand((unsigned)time(NULL));
    fillArray(array, SIZE);
    qsort(array, SIZE, sizeof(int), cmp);

    printArray(array, SIZE);
    printf("Enter value you want to find in the array: ");
    scanf("%d", &searchNum);

    if (binSearch(array, SIZE, searchNum))
        printf("Number %d was found in the array ", searchNum);
    else
        printf("Number %d wasn't found in the array ", searchNum);

    return 0;

}


int cmp(const void* p1, const void* p2) {

    const int* pnum1 = (const int*)p1;
    const int* pnum2 = (const int*)p2;

    return *pnum1 - *pnum2;

}

void fillArray(int array[], int size) {

    for (int i = 0; i < size; i++)
        array[i] = 1 + rand() % 500;

}

void printArray(int array[], int size) {

    for (int i = 0; i < size; i++) {
        printf("%5d", array[i]);
        if (!((i + 1) % 10)) putchar('\n');
    }

}

bool binSearch(int array[], int size, int num) {

    int a = 0;
    int b = size - 1;
    int mid;

    while (a <= b) {

        mid = (a + b) / 2;

        if (array[mid] > num)
            b = mid - 1;
        else if (array[mid] < num)
            a = mid + 1;
        else
            return true;

    }

    return false;

}