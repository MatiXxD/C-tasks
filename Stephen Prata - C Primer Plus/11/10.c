#include <stdio.h>

#define SIZE 100

void cleanBuffer();
char* s_gets(char* str, int size);
void dltSpcs(char* str);

int main(){

    char str[SIZE];
    str[0] = 'a';

    puts("Enter string:");
    s_gets(str, SIZE);
    while(str[0]){

        printf("String with spaces:\n%s\n", str);
        dltSpcs(str);
        printf("String without spaces:\n%s\n", str);

        puts("\nEnter next string (empty string to exit)");
        s_gets(str, SIZE);

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

void dltSpcs(char* str){

    for(int i = 0 ; str[i] ; i++){
        if(str[i] == ' ')
            for(int j = i ; str[j] ; j++)
                str[j] = str[j+1];
    }

}