#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void power2(unsigned num, unsigned const pow);

int main(void) {
    
    unsigned num;
    unsigned pow;

    printf("Enter number: ");
    scanf_s("%u", &num);
    printf("Enter pow for the number: ");
    scanf_s("%u", &pow);

    power2(num, pow);

    return 0; 
} 

void power2(unsigned num, unsigned const pow) {

    unsigned temp = num;
    unsigned mask = 1 << 31;

    for (int i = 0; i < pow; i++) 
        num <<= 1;


    printf("The result of function power2:\n");
    printf("power2(%d) : %d = ", temp, num);
    for (int i = 0; i < 32; i++) {

        putchar(mask & num ? '1' : '0');
        num <<= 1;

        if (!((i + 1) % 8))
            printf(" ");

    }

}