/* Exercise 5.41 Solution */
#include <stdio.h>

long factorial(long);
void printRecursion(int);

int main()
{
    int i;

    for (i = 0; i <= 10; i++) {

        printf("%2d! = %ld\n", i, factorial(i));
        puts("\n------------------------------------------------------\n");

    }

    return 0;
}

long factorial(long number)
{
    if (number <= 1)
        return 1;

    else {
        printRecursion(number);
        return (number * factorial(number - 1));
    }

}

void printRecursion(int n)
{
    printf("number = %*d\n", n, n);
}
