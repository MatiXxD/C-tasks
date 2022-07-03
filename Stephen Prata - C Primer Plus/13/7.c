#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

char* makeStr(char* line);

int main(int argc, char* argv[]){

    FILE *f1, *f2;
    char *retVal1, *retVal2;
    char line1[SIZE];
    char line2[SIZE];

    if(argc < 3){
        puts("You have to enter 2 file's name.");
        exit(EXIT_FAILURE);
    }

    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");
    if(f1 == NULL || f2 == NULL){
        puts("Can't open files.");
        exit(EXIT_FAILURE);
    }

    puts("Output:");
    retVal1 = fgets(line1, SIZE, f1);
    retVal2 = fgets(line2, SIZE, f2);
    while(retVal1 != NULL && retVal2 != NULL){
        printf("%s %s\n", makeStr(line1), makeStr(line2));
        retVal1 = fgets(line1, SIZE, f1);
        retVal2 = fgets(line2, SIZE, f2);
    }

    FILE* f;
    if(retVal1 == NULL) f = f2;
    else f = f1;
    while(fgets(line1, SIZE, f) != NULL)
        fputs(line1, stdout);
    putchar('\n');

    fclose(f1);
    fclose(f2);

    return 0;

}

char* makeStr(char* line){

    char* retVal = line;

    while(*line != '\n')
        line++;
    *line = '\0';

    return retVal;

}
