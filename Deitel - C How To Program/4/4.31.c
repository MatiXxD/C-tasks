#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

    int i;
    int j;

    for (i = 4; i >= 0; i--) {

        j = i;
        while (j--)
            printf(" ");

        j = 9 - 2 * i;
        while (j--)
            printf("*");

        j = i;
        while (j--)
            printf(" ");

        puts(" ");

    }

    for (i = 1; i <= 4; i++) {

        j = i;
        while (j--)
            printf(" ");

        j = 9 - 2 * i;
        while (j--)
            printf("*");

        j = i;
        while (j--)
            printf(" ");

        puts(" ");

    }

    return 0;

}