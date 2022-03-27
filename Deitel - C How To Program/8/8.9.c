#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

int main(void) {

    char str1[SIZE];
    char str2[SIZE];

    puts("Enter first string:");
    gets_s(str1, SIZE);
    puts("Enter second string:");
    gets_s(str2, SIZE);

    printf("\nstr1 %c str2\n", 
        strcmp(str1, str2) == 0 ? '=' : strcmp(str1, str2) < 0 ? '<' : '>');

    return 0;

}