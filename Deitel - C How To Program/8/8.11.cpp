#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 100

int main(void) {

    srand((unsigned int)time(NULL));

    char a = 'Y';
    char checkChr = '1';

    char string[] = "Sample string";


    const char* article[] = { "the", "a", "one", "some", "any" };
    const char* noun[] = { "boy", "girl", "dog", "town", "car" };
    const char* verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
    const char* preposition[] = { "to", "from", "over", "on" };

    while (a == 'Y') {

        int temp;

        char mainStr[50];
        char tempStr[10];


        strcpy(mainStr, article[rand() % (sizeof(article) / 8)]);
        mainStr[0] = toupper(mainStr[0]);
        temp = strlen(mainStr);
        mainStr[temp] = ' ';
        mainStr[temp + 1] = '\0';

        strcpy(tempStr, noun[rand() % (sizeof(noun) / 8)]);
        strcat(mainStr, tempStr);
        temp = strlen(mainStr);
        mainStr[temp] = ' ';
        mainStr[temp + 1] = '\0';

        strcpy(tempStr, verb[rand() % (sizeof(verb) / 8)]);
        strcat(mainStr, tempStr);
        temp = strlen(mainStr);
        mainStr[temp] = ' ';
        mainStr[temp + 1] = '\0';

        strcpy(tempStr, preposition[rand() % (sizeof(preposition) / 8)]);
        strcat(mainStr, tempStr);
        temp = strlen(mainStr);
        mainStr[temp] = ' ';
        mainStr[temp + 1] = '\0';

        strcpy(tempStr, article[rand() % (sizeof(article) / 8)]);
        strcat(mainStr, tempStr);
        temp = strlen(mainStr);
        mainStr[temp] = ' ';
        mainStr[temp + 1] = '\0';

        strcpy(tempStr, noun[rand() % (sizeof(noun) / 8)]);
        strcat(mainStr, tempStr);
        temp = strlen(mainStr);
        mainStr[temp] = '.';
        mainStr[temp + 1] = '\0';


        printf("The random string is:\n%s\n", mainStr);

        puts("\nIf you want to continue press Y and then enter\n");
        while (checkChr != '\n') {

            a = getchar();
            checkChr = getchar();

        }
        checkChr = '1';
    }

    return 0;

}