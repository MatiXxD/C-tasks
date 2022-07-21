#include <stdio.h>
#include "1.h"


int main(void){

    printf("%d + %d = %d\n", 1, 4, SUM(1, 4));
    printf("%d - %d = %d\n", 5, 3, DIFF(5, 3));
    printf("%d * %d = %d\n", 2, 7, MLT(2, 7));
    printf("%d / %d = %d\n", 12, 3, DIV(12, 3));

    return 0;

}