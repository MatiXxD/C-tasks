#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {

    const int SIZE = 1000;
    char str[SIZE];
    char* word;
    bool flag = false;

    puts("Enter string:");
    gets_s(str, SIZE);

    word = strstr(str, " b");
    printf("%s\n", strtok(word, " "));
    word = word + 1;
    while (word != NULL) {

        if(flag)
            printf("%s\n", word);

        word = strtok(NULL, " ");
        if ((word != NULL) && (word[0] != 'b')) 
            flag = false;
        else if (word != NULL)
            flag = true;

    }

    return 0;

}