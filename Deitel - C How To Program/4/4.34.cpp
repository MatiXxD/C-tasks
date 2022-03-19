#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

    int i;
    int number;
    int temp;

    printf("%s\t\t%s\t\t%s\t\t%s\n", "Binary", "Octal", "Decimal", "Hexadecimal");

    for (i = 1; i <= 256; i++) {

        /////////////////////////BINARY///////////////////////////
        
        number = i;

        printf("%c", number == 256 ? '1' : '0');
        number %= 256;

        printf("%c", number < 256 && number >= 128 ? '1' : '0');
        number %= 128;

        printf("%c", number < 128 && number >= 64 ? '1' : '0');
        number %= 64;

        printf("%c", number < 64 && number >= 32 ? '1' : '0');
        number %= 32;

        printf("%c", number < 32 && number >= 16 ? '1' : '0');
        number %= 16;

        printf("%c", number < 16 && number >= 8 ? '1' : '0');
        number %= 8;

        printf("%c", number < 8 && number >= 4 ? '1' : '0');
        number %= 4;

        printf("%c", number < 4 && number >= 2 ? '1' : '0');
        number %= 2;

        printf("%c\t", number < 2 && number >= 1 ? '1' : '0');
        


        /////////////////////////OCTAL///////////////////////////

        number = i;

        printf("%d", number < 512 && number >= 64 ? number / 64 : 0);
        number %= 64;

        printf("%d", number < 64 && number >= 8 ? number / 8 : 0);
        number %= 8;

        printf("%d\t\t", number < 8 && number >= 1 ? number : 0);

   

        /////////////////////////DECIMAL///////////////////////////
        printf("%d\t\t", i);



        /////////////////////////HEXADECIMAL///////////////////////////

        number = i;

        printf("%d", number == 256 ? 1 : 0);
        number %= 256;

        if (number < 256 && number >= 16) {

            temp = number / 16;
            number %= 16;

        }

        else
            temp = 0;


        if (temp <= 9)
            printf("%d", temp);
        else
            printf("%c", 'A' + (temp - 10));

        if (number <= 9)
            printf("%d", number);
        else
            printf("%c", 'A' + (number - 10));
        

        puts("");

    }

    return 0;

}