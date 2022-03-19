#include <stdio.h>

int main(void) {

    int i = 0;


    while (i <= 3000000) {

        if (!(i % 1000000))
            printf("%d\n", i);

        i++;
    }

    return 0;
}