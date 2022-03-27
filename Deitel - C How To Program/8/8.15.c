#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void printLec(char str[]);

int main(void) {

    const int SIZE = 1000;
    char str[SIZE];

    printf("Enter your string\n");
    gets_s(str, SIZE);
    printLec(str);

    return 0;

}

void printLec(char str[]) {

    char* newStr;

    if ((newStr = strtok(str, " ")) == NULL)
        return;

    else {

        printLec(strtok(NULL, "\0"));
        printf("\n%s\n", newStr);

    }

}