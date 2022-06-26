#include <stdio.h>

#define SIZE 100

int searchInStr(char* str, char ch);
void clcBuff();

int main(void){

    char ch;
    char answer = 'y';
    char str[SIZE];

    while(answer != 'q'){

        puts("Enter string:");
        fgets(str, SIZE, stdin);
        puts("Enter char value:");
        ch = getchar();
        clcBuff();

        int find = searchInStr(str, ch);
        if(find)
            printf("'%c' was found in the string %d times.\n", ch, find);
        else
            printf("'%c' wasn't found in the string.\n", ch);

        printf("Print 'q' to exit: ");
        answer = getchar();
        putchar('\n');
        clcBuff();

    }

    return 0;

}

int searchInStr(char* str, char ch){

    int count = 0;

    while(*str)
        if(*str++ == ch) count++;
    
    return count;

}

void clcBuff(){

    while(getchar() != '\n') continue;

}