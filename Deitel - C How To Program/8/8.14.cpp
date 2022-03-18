#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


int main(void) {

    char phoneNumber[15];
    int region;
    char* convertNumber;
    char *trash1, *trash2;

    puts("Enter phone number in (555) 555-5555 format:");
    gets_s(phoneNumber, 15);

    trash1 = strtok(phoneNumber, "(");
    region = atoi(strtok(trash1, ")"));
    trash2 = strtok(NULL, " ");
    convertNumber = strcat(trash2, strtok(NULL, "-"));

    printf("Region - %d\nConvertNumber - %s", region, convertNumber);

    return 0;

}