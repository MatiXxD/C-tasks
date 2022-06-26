#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

void cleanBuffer();
char* s_gets(char* str, int size);
char* revStr(const char* str);

int main(){

    char answer = '1';
    char str[SIZE];

    while(answer != 'q'){
        
        puts("Enter your string:");
        s_gets(str, SIZE);

        char* reverseStr = revStr(str);
        printf("Start string is:\n%s\n", str);
        printf("Reversed string is:\n%s\n", reverseStr);

        printf("Enter 'q' to exit: ");
        answer = tolower(getchar());
        putchar('\n');
        cleanBuffer();       

    }

    return 0;

}

void cleanBuffer(){

    while(getchar() != '\n') continue;

}

char* s_gets(char* str, int size){

    char* retVal = fgets(str, size, stdin);
    if(retVal){

        while(*str != '\n' && *str != '\n')
            str++;

        if(*str == '\n')
            *str = '\0';
        else
            cleanBuffer();

    }

    return retVal;

}

char* revStr(const char* str){

    if (str == NULL) return NULL;

    char newStr[SIZE];
    char* retVal = newStr;

    int i = 0;
    int j = strlen(str);
    newStr[j--] = '\0';
    while(str[i])
        newStr[j--] = str[i++];

    return retVal;

}