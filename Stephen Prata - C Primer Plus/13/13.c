#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getFileSize(const char* name, int* rowsPtr, int* colsPtr);
void getInput(int rows, int cols, int numArr[rows][cols], const char* name);
void convertNumsToStrs(int rows, int cols, const int numArr[rows][cols], char strArr[rows][cols+1]);
void printStrs(int rows, int cols, const char strArr[rows][cols+1], const char* name);

int main(int argc, char* argv[]){

    if(argc < 2){
        puts("You didn't enter file's name.");
        exit(EXIT_FAILURE);
    }

    int rows, cols;
    getFileSize(argv[1], &rows, &cols);
    int numArr[rows][cols];
    char strArr[rows][cols + 1];

    getInput(rows, cols, numArr, argv[1]);
    convertNumsToStrs(rows, cols, numArr, strArr);
    printStrs(rows, cols, strArr, argv[1]);

    return 0;

}

void getFileSize(const char* name, int* rowsPtr, int* colsPtr){

    char ch;
    *rowsPtr = 1;

    FILE *f = fopen(name, "r");
    if(f == NULL){
        printf("File %s wasn't opened.\n", name);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(f)) != EOF){
        if(ch == '\n'){
            (*rowsPtr)++;
        }
        else if(ch != ' ' && ch != '\t')
            (*colsPtr)++;
    }

    *colsPtr /= *rowsPtr;
    printf("Detected size is %d X %d\n", *rowsPtr, *colsPtr);

    fclose(f);

}

void getInput(int rows, int cols, int numArr[rows][cols], const char* name){

    FILE *f = fopen(name, "r");
    if(f == NULL){
        printf("File %s wasn't opened.\n", name);
        exit(EXIT_FAILURE);
    }

    int temp, check;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            check = fscanf(f, "%d", &temp);
            if(check) numArr[i][j] = temp;
            else numArr[i][j] = 0;
        }
    }

    fclose(f);

}

void convertNumsToStrs(int rows, int cols, const int numArr[rows][cols], char strArr[rows][cols+1]){

    const char symbArr[] = {' ', '.', '\'', ':', '~', '*', '=', '?', '%', '#'};

    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++)
            strArr[i][j] = symbArr[numArr[i][j]];
        strArr[i][cols] = '\0';
    }

}

void printStrs(int rows, int cols, const char strArr[rows][cols+1], const char* name){

    int size = strlen(name) + 5;
    char nameOut[size];
    strncpy(nameOut, name, size - 5);
    strcat(nameOut, ".out");
    nameOut[size-1] = '\0';

    FILE *f = fopen(nameOut, "w");
    if(f == NULL){
        printf("Can't open file %s to write output.\n", name);
        exit(EXIT_FAILURE);
    }

    for(int i = 0 ; i < rows ; i++)
        fprintf(f, "%s\n", strArr[i]);

    printf("Output was written in file \"%s\".\n", nameOut);
    fclose(f);

}
