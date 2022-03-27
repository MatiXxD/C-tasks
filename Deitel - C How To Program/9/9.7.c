#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {

    srand((unsigned int)time(NULL));

    const int SIZE = 10;
    int arr[SIZE];
    int count = 0;

    printf("%-10s%-20s\n", "Value", "Total characters");
    for (int i = 0; i < SIZE; i++) {

        int temp;

        arr[i] = 1 + rand() % 1000;
        printf("%d%n%10s", arr[i], &temp, "");
        count += temp;
        printf("%-20d\n", count);

    }

    getchar();
    getchar();

    return 0;

}
