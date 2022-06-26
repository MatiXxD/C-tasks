#include <stdio.h>

#define SIZE 100

void getWord(char* str);

int main(void){

    char str[SIZE];

    getWord(str);
    printf("First word in your input is:\n%s\n", str);

    return 0;

}

void getWord(char* str){

    char ch;
    int i = 0;

    while((ch = getchar()) == ' ' || ch == '\t' || ch == '\n') continue;
    str[i++] = ch;
    while((ch = getchar()) != ' ' && ch != '\t' && ch != '\n'){
        str[i++] = ch;
        if(i > SIZE - 2) 
            break;
    }
    str[i] = '\0';
    while(getchar() != '\n') continue;

}