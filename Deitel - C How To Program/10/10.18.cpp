#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void displayBits(unsigned value); 

int main(void) {

    unsigned x; 

    printf("Enter an unsigned integer: ");
    scanf_s("%u", &x);

    displayBits(x);
    return 0; 
} 


void displayBits(unsigned value) {

    unsigned c; 
    unsigned move = 8 * (unsigned)sizeof(unsigned) - 1;
    unsigned displayMask = 1 << move;

    printf("%10u = ", value);

   
    for (c = 1; c <= move; c++) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; 

        if (c % 8 == 0) { 
            putchar(' ');
        } 
    } 

    putchar('\n');
} 