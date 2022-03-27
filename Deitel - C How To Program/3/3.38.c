#include <stdio.h>

int main(void) {

    int counter = 1;

    while (counter <= 100) {

        printf("%s", "*");

        if (!(counter % 10))
            puts("");

        counter++;

    }

    return 0;
}