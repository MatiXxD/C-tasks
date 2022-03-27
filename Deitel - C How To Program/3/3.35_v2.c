#include <stdio.h>

int main(void) {

    int number, dignit, result;
    int fstDign, secDign, thrDign, fourDign, fiveDign;
    int counter = 1;
    int divider = 10000;

    puts("Enter integer five-dignit number");
    scanf_s("%d", &number);
    result = number;

    while (counter <= 5) {
        
        dignit = result / divider;
        result -= dignit * divider;

        if (counter == 1)
            fstDign = dignit;

        else if (counter == 2)
            secDign = dignit;

        else if (counter == 3)
            thrDign = dignit;

        else if (counter == 4)
            fourDign = dignit;

        else 
            fiveDign = dignit;

        divider /= 10;
        counter++;
    }

    if (fstDign == fiveDign) {
        if (secDign == fourDign)
            puts("This number is palindrome");
    }

    else
        puts("This number isn't palindrome");

    return 0;
}