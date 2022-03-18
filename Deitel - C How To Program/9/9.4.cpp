#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {

    unsigned int hex;
    int hour1, minutes1, seconds1;
    int hour2, minutes2, seconds2;
    char str1[1000];
    char str2[1000];
    char trashStr[1000];
   

    printf("%-15.8u\n\n", 40000);
    scanf_s("%x", &hex);
    printf("\n%+d\t%d\n\n", 200, 200);
    printf("%#x\n\n", 100);
    scanf_s("%[^p]%s", str1, 1000, trashStr, 1000);
    printf("\n%09.3f\n\n", 1.234);
    scanf_s("%d%*c%d%*c%d", &hour1, &minutes1, &seconds1);
    puts("");
    scanf_s("\"%[^\"]", str2, 1000);
    printf("%s", str2);
    scanf_s("%d:%d:%d", &hour2, &minutes2, &seconds2);
    puts("");

    return 0;

}