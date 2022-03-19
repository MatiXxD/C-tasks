#include <stdio.h>

int main(void) {

    int number, dignit, tempSum, j;
    int i = 0;
    int newNumber = 0;
    int divider = 10;
    int pos = 1;

    puts("Enter number which contain only 0 and 1");
    scanf_s("%d", &number);

    while (i != 228) {

        tempSum = 1;
        j = pos;

        if (10 * number - divider < 0)
            i = 228;

        else {

            dignit = (number % divider) / (divider / 10);

            if (dignit == 0)
                newNumber += 0;

            else if (dignit == 1) {

                if (pos == 1)
                    newNumber = 1;

                else {

                    while (j-- > 1)
                        tempSum *= 2;

                    newNumber += tempSum;
                }

            }

            else
                puts("You have entered something different from 0 and 1");

        }
        
        divider *= 10;
        pos++;
    }

    printf("%d - %d", number, newNumber);

    return 0;
}