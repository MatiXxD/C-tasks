#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char* argv[]){

    char *findStr, *retVal;
    char str[SIZE];

    if(argc < 3){
        puts("You didn't enter all arguments.");
        exit(EXIT_FAILURE);
    }

    FILE* f = fopen(argv[2], "r");
    if(f == NULL){
        printf("File %s wasn't open.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("String which contains %s:\n", argv[1]);
    retVal = fgets(str, SIZE, f);
    while(retVal){
        findStr = strstr(str, argv[1]);
        if(findStr)
            fputs(findStr, stdout);
        retVal = fgets(str, SIZE, f);
    }

    if (fclose(f) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;

}
