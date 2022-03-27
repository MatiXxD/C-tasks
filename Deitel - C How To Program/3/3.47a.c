#include <stdio.h>

int main(void) {

    int number = -1;
    unsigned int i;
    unsigned int fctl = 1;

    while (number < 0) {

        puts("Enter integer POSITIVE number");
        scanf_s("%d", &number);

    }

    i = number;

    while (i) {

        fctl *= i;
        i--;

    }

    printf("Factorial for number %d is %d\n", number, fctl);

    return 0;
}