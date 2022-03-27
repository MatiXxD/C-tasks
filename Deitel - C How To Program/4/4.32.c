#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

    int i;
    int j;
    int rows;

    puts("Enter integer even number (number of rows from 1 to 19)");
    scanf_s("%d", &rows);


    for (i = (rows - 1) / 2 ; i >= 0; i--) {

        j = i;
        while (j--)
            printf(" ");

        j = rows - 2 * i;
        while (j--)
            printf("*");

        j = i;
        while (j--)
            printf(" ");

        puts(" ");

    }

    for (i = 1 ; i <= (rows - 1) / 2; i++) {

        j = i;
        while (j--)
            printf(" ");

        j = rows - 2 * i;
        while (j--)
            printf("*");

        j = i;
        while (j--)
            printf(" ");

        puts(" ");

    }

    return 0;

}