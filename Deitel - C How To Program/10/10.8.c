#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
 
union integer {

    char c;
    short s;
    int i;
    long b;

};

int main(void) {
    
    union integer nums;
    scanf_s("%c%hd%d%ld", &nums.c, 1, &nums.s, &nums.i, &nums.b);
    printf("%c\n%hd\n%ld\n%d\n", nums.c, nums.s, nums.b, nums.i);

    return 0; 
} 