#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 200
#define WORD_SIZE 20

void printWord(char* word);

int main(void) {

    char str[SIZE];
    char* word;

    puts("Enter your string:");
    gets_s(str, SIZE);

    puts("Converte string is:");
    word = strtok(str, " ");
    printWord(word);
    while ((word = strtok(NULL, " ")) != NULL)
        printWord(word);


    return 0;

}

void printWord(char* word) {

    char tempStr[WORD_SIZE];
    const int size = strlen(word);
;                    
    for (int i = 0; i < size; i++)
        tempStr[i] = word[i + 1];
    tempStr[size - 1] = tolower(word[0]);
    tempStr[size] = 'a';
    tempStr[size + 1] = 'y';
    tempStr[size + 2] = '\0';

    printf("%s ", tempStr);

}