#include <stdio.h>
#include <string.h>

#define SIZE 100

char* mystrchr(char* str, char ch);
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

        char* find = mystrchr(str, ch);
        if(find)
            printf("'%c' was found in the string. String which starts with '%c':\n%s", 
                ch, ch, find);
        else
            printf("'%c' wasn't found in the string.\n", ch);

        printf("Print 'q' to exit: ");
        answer = getchar();
        putchar('\n');
        clcBuff();

    }

    return 0;

}

char* mystrchr(char* str, char ch){

    for(int i = 0 ; i < strlen(str) ; i++)
        if(str[i] == ch) return str+i;

    return NULL;

}

void clcBuff(){

    while(getchar() != '\n') continue;

}