#include <stdio.h>
#include <stdlib.h>


#define PRINTARRAY(arr, i) arr[i]


int main(void) {

    int arr[] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < 5; i++)
        printf("%d ", PRINTARRAY(arr, i));
    puts("");

    return 0;

}