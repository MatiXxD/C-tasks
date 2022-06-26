#include <stdio.h>
#include <ctype.h>

#define SIZE 100

char* s_gets(char* str, int size);
char* mystrncpy(char* str1, const char* str2, unsigned n);
void clearBuffer();

int main(void){

    int n;
    char answer = '1';
    char str1[SIZE];
    char str2[SIZE];

    while(answer != 'q'){

        puts("Enter string you want to copy:");
        s_gets(str2, SIZE);
        puts("Enter number of digits you want to copy:");
        scanf("%d", &n);
        clearBuffer();                                                      // To get \n from previous scanf()

        char* checkVal = mystrncpy(str1, str2, n);
        if(checkVal)
            printf("Copied string is:\n%s\n", str1);
        else
            puts("String wasn't copied.");

        puts("If you want to stop print 'q'");
        answer = tolower(getchar());
        clearBuffer();

    }

    return 0;

}

char* s_gets(char* str, int size){

    char* retVal = fgets(str, size, stdin);
    if(retVal){

        while(*str != '\n' && *str != '\0')
            str++;
        
        if(*str == '\n')
            *str = '\0';
        else
            while(getchar() != '\n') continue;

    }

    return retVal;

}

char* mystrncpy(char* str1, const char* str2, unsigned n){

    char* startPtr = str1;

    if(n > SIZE){
        puts("N is bigger than size of the string. "
            "Now n = size.");
        n = SIZE;
    }

    int i = 0;
    while(n--){
        if(str2[i])
            *str1++ = str2[i++];
        else
            *str1++ = '\0';

    }
    *str1 = '\0';

    return startPtr;

}

void clearBuffer(){

    while(getchar() != '\n') continue;

}