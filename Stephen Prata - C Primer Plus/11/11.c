#include <stdio.h>
#include <string.h>

#define SIZE 100
#define LIM 10

void cleanBuffer();
char* s_gets(char* str, int size);
int inputStr(char *strArr[]);

int main(void){

    char strArr[LIM][SIZE];



    return 0;

}

void cleanBuffer(){

    while(getchar() != '\n') continue;

}

char* s_gets(char* str, int size){

    char* retVal = fgets(str, size, stdin);

}
