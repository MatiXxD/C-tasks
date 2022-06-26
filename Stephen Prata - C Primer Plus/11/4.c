#include <stdio.h>

#define SIZE 100

char* getWord(char* str, int n);

int main(void){

    char str[SIZE];

    char* strPtr = getWord(str, 10);
    if(strPtr != NULL)
        printf("First word in your input is:\n%s\n", strPtr);
    else
        puts("Wrong input!");

    return 0;

}

char* getWord(char* str, int n){

    if(n > SIZE - 1 || n < 2)
        return NULL;

    char ch;
    int i = 0;

    while((ch = getchar()) == ' ' || ch == '\t' || ch == '\n') continue;
    str[i++] = ch;
    n--;
    while((ch = getchar()) != ' ' && ch != '\t' && ch != '\n' && n--){
        str[i++] = ch;
        if(i > SIZE - 2) 
            break;
    }
    str[i] = '\0';
    while(getchar() != '\n') continue;

    return str;

}