#include <stdio.h>

int main(void) {

    int a, b, c;

    puts("Input three integer number");
    scanf_s("%d%d%d", &a, &b, &c);

    if (a * a + b * b == c * c)
        printf("It is right triangle\n");

    else if (a * a + c * c == b * b)
        printf("It is right triangle\n");

    else if (c * c + b * b == a * a)
        printf("It is right triangle\n");

    else
        printf("It isn't right triangle\n");

    return 0;
}