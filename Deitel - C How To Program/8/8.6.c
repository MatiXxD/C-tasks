#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    char s[100];
    char s1[100];
    char s2[100];

    puts("Enter string");
    gets_s(s, 100);

    int i = 0;
    while (s[i] != '\0') {

        s1[i] = toupper(s[i]);
        s2[i] = tolower(s[i]);

        i++;

    }
    s1[i] = s2[i] = '\0';

    printf("The upper string is %s\nThe lower string is %s\n", s1, s2);

    return 0; 

} 