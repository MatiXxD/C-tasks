#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void printNum(unsigned num);
void reverseBits(unsigned num);

int main(void) {
    
    unsigned num;

    printf("Enter number: ");
    scanf_s("%u", &num);

    printNum(num);
    reverseBits(num);

    return 0; 
}

void printNum(unsigned num) {

    unsigned mask = 1 << 31;

    for (int i = 0; i <= 31; i++) {

        putchar(mask & num ? '1' : '0');
        num <<= 1;

        if (!((i + 1) % 8))
            printf(" ");

    }

    putchar('\n');

}

void reverseBits(unsigned num) {

    unsigned mask = 1;

    for (int i = 0; i <= 31; i++) {

        putchar(mask & num ? '1' : '0');
        mask <<= 1;

        if (!((i + 1) % 8))
            printf(" ");

    }

    putchar('\n');

}