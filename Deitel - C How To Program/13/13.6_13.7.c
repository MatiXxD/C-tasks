#include <stdio.h>
#include <stdlib.h>


#define MINIMUM2(x, y) (x) < (y) ? (x) : (y)
#define MINIMUM3(x, y, z) MINIMUM2((x), MINIMUM2((y), (z)))


int main(void) {

    double min;
    double num1, num2, num3;

    printf("Enter two numbers: ");
    scanf_s("%lf %lf", &num1, &num2);

    min = MINIMUM2(num1, num2);
    printf("Min is %.2lf\n", min);


    puts("");


    printf("Enter three numbers: ");
    scanf_s("%lf %lf %lf", &num1, &num2, &num3);

    min = MINIMUM3(num1, num2, num3);
    printf("Min is %.2lf\n", min);

    return 0;

}