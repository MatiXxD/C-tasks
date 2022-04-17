#include <stdio.h>
#include <stdlib.h>


int main() {

    int i = 1;

start:

    if (i > 1 && i < 5) {

        printf("*");
        printf("   ");
        printf("*\n");

        i++;
        goto start;

    }
    else if (i == 1 || i == 5) {

        printf("*****\n");

        i++;
        goto start;

    }
    else {
        goto end;
    }

end:

    return 0;

}