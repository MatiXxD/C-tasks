#include <stdio.h>

int main(void) {

    int number;
    int dignit;
    int divider1 = 1;
    int divider2 = 10;
    int size = 0;
    int count = 0;

    puts("Enter number");
    scanf_s("%d", &number);

    while (number - divider1 > 0) {

        size++;
        divider1 *= 10;

    }

    while (size--) {

        dignit = (number % divider2) / (divider2 / 10);

        if (dignit == 7)
            count++;

        divider2 *= 10;

    }

    printf("Number %d contain %d times number '7'\n", number, count);

    return 0;
}