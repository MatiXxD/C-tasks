#include <stdio.h>

int main(void) {

    float a, b, c;
    int err;

    puts("Enter three number");
    scanf_s("%f%f%f", &a, &b, &c);

    if (!(a + b > c))
        printf("Cant be sides because %.2f + %.2f <= %.2f\n", a, b, c);

    else if (!(b + c > a))
        printf("Cant be sides because %.2f + %.2f <= %.2f\n", b, c, a);

    else if (!(a + c > b))
        printf("Cant be sides because %.2f + %.2f <= %.2f\n", a, c, b);

    else
        puts("Can be sides");

    return 0;
}