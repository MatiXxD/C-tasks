#include <stdio.h>
#include <stdlib.h>


#define SUMARRAY(arr, n) sum(arr, (n-1))

int sum(int arr[], int n);

int main(void) {

    int arr[] = { 1, 2, 3, 4, 5 };

    printf("Sum of array is %d", SUMARRAY(arr, 5));

    return 0;

}

int sum(int arr[], int n) {

    return n != 0 ? arr[n] + sum(arr, n - 1) : arr[0];

}