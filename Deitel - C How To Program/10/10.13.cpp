#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void printChar(unsigned char num);
void packCharacters(unsigned char a, unsigned char b);

int main(void) {
    
    unsigned char a, b;

    printf("Enter two numbers: ");
    scanf_s("%c%c", &a, 1, &b, 1);

    printChar(a);
    printChar(b);
    putchar('\n');
    packCharacters(a, b);

    return 0; 
} 

void packCharacters(unsigned char a, unsigned char b) {

    unsigned packedNum = a << 8;
    packedNum |= b;

    unsigned mask = 1 << 15;
    unsigned savePackedNum = packedNum;
    for (int i = 0; i <= 15; i++) {

        putchar(mask & packedNum ? '1' : '0');
        packedNum <<= 1;

        if (!((i + 1) % 8))
            printf(" ");
    }
    printf("= %u", savePackedNum);

}

void printChar(unsigned char num) {

    unsigned char mask = 1 << 7;

    for (int i = 0; i <= 7; i++) {

        putchar(mask & num ? '1' : '0');
        num <<= 1;

    }

    printf(" ");

}