#include <stdio.h>

int main(void) {

    int number;
    int dignit;
    int divider1 = 1;
    int multiplier = 1;
    int divider2 = 10;
    int size = 0;
    int newNumber = 0;

    puts("Enter five-dignit number which contain only 0 and 1");
    scanf_s("%d", &number);

    while (number - divider1 > 0) {

        size++;
        divider1 *= 10;

    }

    while (size--) {

        dignit = (number % divider2) / (divider2 / 10);
        newNumber += ((dignit == 1) ? 1 : 0) * multiplier;
        multiplier *= 2;
        divider2 *= 10;

    }

    printf("\nBinary number %d in decimal system is %d\n", number, newNumber);

    return 0;
}