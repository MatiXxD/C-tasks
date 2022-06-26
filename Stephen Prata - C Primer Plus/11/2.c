#include <stdio.h>

#define SIZE 100

char *getn(char *str, int n);

int main(void){

    char str[SIZE];

    getn(str, 10);

    if(str[0] != '\0') 
        printf("Your string is:\n%s\n", str);
    else
        puts("Wrong input!");

    return 0;

}

char *getn(char *str, int n){

    if (n > SIZE - 1) return "";
    
    int i;
    
    puts("Enter values:");
    for(i = 0 ; i < n ; i++){
        char temp = getchar();
        if(temp != ' ' && temp != '\t' && temp != '\n')
            str[i] = temp;
        else
            break;
    }
    str[i] = '\0';

    return str;

}