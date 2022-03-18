#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {

    const int SIZE = 500;
    char str1[SIZE];
    char str2[SIZE];
    char* searchPtr1;
    char* searchPtr2;

    puts("Enter two strings:");
    gets_s(str1, SIZE);
    gets_s(str2, SIZE);

    if ((searchPtr1 = strstr(str1, str2)) != NULL) {

        printf("1) The search string is \"%s\"\n", searchPtr1);

        if ((searchPtr2 = strstr(searchPtr1 + 1, str2)) != NULL)
            printf("2) The search string is \"%s\"", searchPtr2);

    }


    return 0;

}