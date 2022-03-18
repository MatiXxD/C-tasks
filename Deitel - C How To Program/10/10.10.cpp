#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void print(int num);

int main(void) {
    
    int num;

    puts("Enter number:");
    scanf_s("%d", &num);

    print(num);
    print(num >> 4);

    return 0; 
} 

void print(int num) {

    int mask = 1 << 31;

    printf("%d = ", num);

    for (int i = 0; i <= 31; i++) {

        putchar(mask & num ? '1' : '0');
        num <<= 1;

        if (!((i + 1) % 8))
            printf(" ");

    }

    puts("");

}