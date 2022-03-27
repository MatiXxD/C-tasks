#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {

    int loop, count;
    double loop2;

    for (count = 1; count < 14; count++)
    {
        switch (count)
        {
        case 1:
            printf("funct    ");      /* header */
            for (loop = 1; loop < 6; loop++)
                printf("%10d ", loop);
            break;
        case 2:
            printf("\nsqrt()    ");
            for (loop = 1; loop < 6; loop++)
                printf("%10.2lf ", sqrt(loop));
            break;
        case 3:
            printf("exp()     ");
            for (loop = 1; loop < 6; loop++)
                printf("%10.2lf ", exp(loop));
            break;
        case 4:
            printf("log()     ");
            for (loop = 1; loop < 6; loop++)
                printf("%10.2lf ", log(loop));
            break;
        case 5:
            printf("log10()   ");
            for (loop = 1; loop < 6; loop++)
                printf("%10.2lf ", log10(loop));
            break;
        case 6:
            printf("pow( 2,x )");
            for (loop = 1; loop < 6; loop++)
                printf("%10.2lf ", pow(2, loop));
            break;
        case 7:
            printf("\n\nfunct     ");      /* header */
            for (loop2 = -1.5; loop2 < 3.0; loop2 += 1.1)
                printf("%10.2lf ", loop2);
            break;
        case 8:
            printf("\nfabs()    ");
            for (loop2 = -1.5; loop2 < 3.0; loop2 += 1.1)
                printf("%10.2lf ", fabs(loop2));
            break;
        case 9:
            printf("ceil()    ");
            for (loop2 = -1.5; loop2 < 3.0; loop2 += 1.1)
                printf("%10.2lf ", ceil(loop2));
            break;
        case 10:
            printf("floor()   ");
            for (loop2 = -1.5; loop2 < 3.0; loop2 += 1.1)
                printf("%10.2lf ", floor(loop2));
            break;
        case 11:
            printf("sin()     ");
            for (loop2 = -1.5; loop2 < 3.0; loop2 += 1.1)
                printf("%10.2lf ", sin(loop2));
            break;
        case 12:
            printf("cos()     ");
            for (loop2 = -1.5; loop2 < 3.0; loop2 += 1.1)
                printf("%10.2lf ", cos(loop2));
            break;
        case 13:
            printf("tan()     ");
            for (loop2 = -1.5; loop2 < 3.0; loop2 += 1.1)
                printf("%10.2lf ", tan(loop2));
            break;
        }

        printf("\n");
    }

    return 0;

}