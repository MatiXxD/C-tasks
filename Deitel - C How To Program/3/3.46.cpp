#include <stdio.h>

int main(void) {

    int number;
    int tempDignit;
    int dignit;
    int divider1 = 1;
    int divider2 = 10;
    int size = 0;
    int newNumber = 0;

    puts("Enter four-dignit integer number");
    scanf_s("%d", &number);

    while (number - divider1 > 0) {

        size++;
        divider1 *= 10;

    }

    while (size--) {

        dignit = (number % divider2) / (divider2 / 10);
        tempDignit = (dignit + 7) % 10;
        newNumber += tempDignit * (divider2 / 10);

        divider2 *= 10;

    }

    printf("Encrypted number is %d\n", newNumber);


    return 0;
}