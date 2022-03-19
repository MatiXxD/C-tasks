#include <stdio.h>

int main(void) {
   
    int number;
    int one, two, three, four, five;


    puts("Enter intger five-digit number");
    scanf_s("%d", &number);

    five = number / 10000;
    four = (number - five * 10000) / 1000;
    three = (number - five * 10000 - four * 1000) / 100;
    two = (number - five * 10000 - four * 1000 - three * 100) / 10;
    one = number - five * 10000 - four * 1000 - three * 100 - two * 10;

    if (one == five) {
        if (two == four)
            puts("This number is palindrome");
    }

    else
        puts("This number isn't palindrome");

    return 0;
}


P. S. 
    five = number / 10000;
    four = (number % 10000) / 1000;
    three = (number % 1000) / 100;
    two = (number % 100) / 10;
    one = (number % 10);

