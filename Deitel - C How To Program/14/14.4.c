#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort(int arr[], int size, int option) {

    for (int i = 0; i < size - 1; i++)
        for (int j = (size - 1); j > i; j--) {

            int temp = arr[j - 1];

            if ((arr[j - 1] > arr[j]) && option == 1) {

                arr[j - 1] = arr[j];
                arr[j] = temp;

            }
            else if ((arr[j - 1] < arr[j]) && option == 2) {

                arr[j - 1] = arr[j];
                arr[j] = temp;

            }

        }

}

int main(int argc, char* argv[]) {

    if (argc == 2) {

        srand((unsigned)time(NULL));

        const int SIZE = 50;
        int numArr[SIZE];

        printf("Array is :\n");
        for (int i = 1; i <= SIZE; i++) {

            int temp = rand() % 100;
            printf("%3d%c", temp, i % 10 ? ' ' : '\n');
            numArr[i - 1] = temp;

        }

        if (!strcmp(argv[1], "-a"))
            bubbleSort(numArr, SIZE, 1);
        else
            bubbleSort(numArr, SIZE, 2);

        printf("Now array is :\n");
        for (int i = 1; i <= SIZE; i++)
            printf("%3d%c", numArr[i - 1], i % 10 ? ' ' : '\n');

    }
    else
        printf("Option wasn't selected!\n");

    return 0;

}