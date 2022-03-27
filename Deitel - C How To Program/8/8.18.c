#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int count(char str[], char key);

int main(void) {

    const int SIZE = 1000;
    char str[SIZE];
    char key;

    puts("Enter your string:");
    gets_s(str, SIZE);
    puts("Enter char which you want to find it the string:");
    scanf_s("%c", &key, 1);

    printf("\n'%c' found %d times in str \"%s\"\n\n", key, count(str, key), str);

    return 0;

}

int count(char str[], char key) {

    int static num = 0;
    char* temp;
    
    if ((temp = strchr(str, key)) == NULL)
        return num;

    else {

        num++;
        count(temp  + 1, key);

    }

}