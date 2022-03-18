#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    char c;
    char test = '1';
    char check[20];
    bool i = true;

    while (i) {

        puts("Enter dignit and then enter to continue");
        
        while (test != '\n') {

            c = getchar();
            test = getchar();

        }

        printf("isdigit(c) = %d\n", isdigit(c));
        printf("isalpha(c) = %d\n", isalpha(c));
        printf("isalnum(c) = %d\n", isalnum(c));
        printf("isxdigit(c) = %d\n", isxdigit(c));
        printf("islower(c) = %d\n", islower(c));
        printf("isupper(c) = %d\n", isupper(c));
        printf("isspace(c) = %d\n", isspace(c));
        printf("iscntrl(c) = %d\n", iscntrl(c));
        printf("ispunct(c) = %d\n", ispunct(c));
        printf("ispritn(c) = %d\n", isprint(c));
        printf("isgraph(c) = %d\n", isgraph(c));


        puts("\nEnter STOP to end entering");
        gets_s(check, 20);

        if (!strcmp(check, "STOP"))
            i = false;
        
        test = '1';

    }

    return 0; 

} 