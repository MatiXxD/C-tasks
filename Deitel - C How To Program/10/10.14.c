#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void printChar(unsigned char num);
void unpackCharacters(unsigned num);

int main(void) {
    
    unsigned num;

    printf("Enter number: ");
    scanf_s("%u", &num);

    unpackCharacters(num);

    return 0; 
} 

void unpackCharacters(unsigned num) {

    unsigned printNum = num;
    unsigned mask = 1 << 15;

    for (int i = 0; i <= 15; i++) {

        putchar(mask & printNum ? '1' : '0');
        printNum <<= 1;

        if (!((i + 1) % 8))
            printf(" ");

    }
    putchar('\n');
    

    unsigned mask1 = 65280;
    unsigned mask2 = 255;

    unsigned char ch1 = (mask1 & num) >> 8;
    unsigned char ch2 = mask2 & num;
    printChar(ch1);
    printChar(ch2);

}

void printChar(unsigned char num) {

    unsigned char mask = 1 << 7;

    printf("%c = ", num);
    for (int i = 0; i <= 7; i++) {

        putchar(mask & num ? '1' : '0');
        num <<= 1;

    }

    printf("\n");

}

//65280     255