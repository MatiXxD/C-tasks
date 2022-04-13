#include <stdio.h>
#include <stdlib.h>


#define SUM(x, y) ((x) + (y))


int main(void) {

    double num1, num2;

    printf("Enter two numbers: ");
    scanf_s("%lf %lf", &num1, &num2);

    printf("The sum of %.2lf and %.2lf is %.2lf\n", num1, num2, SUM(num1, num2));

    return 0;

}