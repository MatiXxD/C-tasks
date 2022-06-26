#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void clearBuffer();
char* s_gets(char* str, int size);
char* string_in(const char* str1, const char* str2);

int main(void){

    char answer = '1';
    char str1[SIZE];
    char str2[SIZE];

    while(answer != 'q'){

        puts("Enter first string:");
        s_gets(str1, SIZE);
        puts("Enter second string:");
        s_gets(str2, SIZE);

        char* retVal = string_in(str1, str2);
        if(retVal)
            printf("\"%s\" was found in \"%s\". Result:\n%s\n", 
                str2, str1, retVal);
        else
            printf("\"%s\" wasn't found in \"%s\".\n", str2, str1);

        printf("Enter 'q' to exit: ");
        answer = tolower(getchar());
        putchar('\n');
        clearBuffer();

    }

    return 0;

}

void clearBuffer(){

    while(getchar() != '\n') continue;

}

char* s_gets(char* str, int size){

    char* retVal = fgets(str, size, stdin);
    if(retVal){

        while(*str != '\n' && *str != '\0') 
            str++;
        
        if(*str == '\n')
            *str = '\0';
        else
            clearBuffer();

    }

    return retVal;

}

char* string_in(const char* str1, const char* str2){

    int i = 0;
    int j = 0;

    while(str1[i] != '\0' && str2[j] != '\0'){
        if(str1[i] == str2[j]){
            i++;
            j++;
        }
        else{
            i++;
            j = 0;
        }
    }

    char* returnValue;
    if(j != 0){
        char copyStr[SIZE];
        strncpy(copyStr, str1, SIZE);
        returnValue = &copyStr[i-j];
    }
    else
        returnValue = NULL;

    return returnValue;

}