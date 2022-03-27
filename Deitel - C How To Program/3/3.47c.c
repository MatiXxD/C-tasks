#include <stdio.h>

int main(void) {

    float e = 1;
    int n = 10;
    int fctl = 1;
    int i = 1;
    int n1 = n;
    float x;

    puts("Enter x to get aprox of exp(x)");
    scanf_s("%f", &x);

    while (n1) {

        fctl *= n1;
        n1--;

    }

    while (n) {
        
        while (i--)
            x *= x;

        e += x / fctl;
        fctl /= n;

        n--;
        i++;

    }
    
    printf("%f", e);

    return 0;
}