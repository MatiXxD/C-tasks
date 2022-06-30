#include <stdio.h>
#include "pe12-2a.h"

int main(void) {

    int mode;
    printf("Enter 0 for metric mode or 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0) {
        getInfo(mode);
        printf("Enter 0 for metric mode or 1 for US mode\n");
        printf("(-1 to exit): ");
        scanf("%d", &mode);
    }

    printf("Program completed.\n");
    return 0;

}
