#include <stdio.h>

int main(void) {

    float e = 1;
    int n = 10;
    int fctl = 1;
    int n1 = n;

    while (n1) {

        fctl *= n1;
        n1--;

    }

    while (n) {

        e += 1.0 / fctl;
        fctl /= n;

        n--;

    }
    
    printf("%f", e);

    return 0;
}