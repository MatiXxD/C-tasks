#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

    int i;
    int units, ten;

    printf("%s\t\t%s\n\n", "Roman", "Decimal");

    for (i = 1; i <= 100; i++) {

        units = i % 10;
        ten = i / 10;

        switch (ten) {

        case 1:
            printf("%s", "X");
            break;

        case 2:
            printf("%s", "XX");
            break;

        case 3:
            printf("%s", "XXX");
            break;

        case 4:
            printf("%s", "XL");
            break;

        case 5:
            printf("%s", "L");
            break;

        case 6:
            printf("%s", "LX");
            break;

        case 7:
            printf("%s", "LXX");
            break;

        case 8:
            printf("%s", "LXXX");
            break;

        case 9:
            printf("%s", "XC");
            break;

        case 10:
            printf("%s", "C");
            break;

        }

        switch (units) {

        case 0:
            printf("%s\t\t%4d\n", "", i);
            break;
            
        case 1:
            printf("%s\t\t%4d\n", "I", i);
            break;

        case 2:
            printf("%s\t\t%4d\n", "II", i);
            break;

        case 3:
            printf("%s\t\t%4d\n", "III", i);
            break;

        case 4:
            printf("%s\t\t%4d\n", "IV", i);
            break;

        case 5:
            printf("%s\t\t%4d\n", "V", i);
            break;

        case 6:
            printf("%s\t\t%4d\n", "VI", i);
            break;

        case 7:
            printf("%s\t\t%4d\n", "VII", i);
            break;

        case 8:
            if (i != 88)
                printf("%s\t\t%4d\n", "VIII", i);
            else
                printf("%s\t%4d\n", "VIII", i);
            break;

        case 9:
            printf("%s\t\t%4d\n", "IX", i);
            break;

        }

    }

    return 0;

}