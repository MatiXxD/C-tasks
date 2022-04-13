#include <stdio.h>
#include <stdlib.h>


#define PI 3.14159
#define BALL_VOLUME(x) ((4.0 / 3) * PI * (x) )


int main(void) {

    for (int i = 1; i <= 10; i++)
        printf("V%d = %lf\n", i, BALL_VOLUME(i));

    return 0;

}