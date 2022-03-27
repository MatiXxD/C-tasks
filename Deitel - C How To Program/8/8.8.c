#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20

int main(void) {

    char arr[SIZE];
    long double sum = 0;

    for (int i = 0; i < 4; i++) {

        printf("Enter %d number:\n", i + 1);

        gets_s(arr, SIZE);
        sum += atof(arr);

    }

    printf("\nSum of numbers is %.2f\n", 2 * sum);

    return 0;

}