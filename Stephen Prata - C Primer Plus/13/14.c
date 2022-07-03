#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 20
#define COLS 30

void getInput(int numArr[ROWS][COLS], const char* name);
void cleanNoise(int numArr[ROWS][COLS]);
int makeAvg(int num, const int cmpArr[]);
void convertNumsToStrs(const int numArr[ROWS][COLS], char strArr[ROWS][COLS+1]);
void printStrs(const char strArr[ROWS][COLS+1], const char* name);

int main(int argc, char* argv[]){

    int numArr[ROWS][COLS];
    char strArr[ROWS][COLS + 1];

    if(argc < 2){
        puts("You didn't enter file's name.");
        exit(EXIT_FAILURE);
    }

    getInput(numArr, argv[1]);
    cleanNoise(numArr);
    convertNumsToStrs(numArr, strArr);
    printStrs(strArr, argv[1]);

    return 0;

}

void getInput(int numArr[ROWS][COLS], const char* name){

    FILE *f = fopen(name, "r");
    if(f == NULL){
        printf("File %s wasn't opened.\n", name);
        exit(EXIT_FAILURE);
    }

    int temp, check;
    for(int i = 0 ; i < ROWS ; i++){
        for(int j = 0 ; j < COLS ; j++){
            check = fscanf(f, "%d", &temp);
            if(check) numArr[i][j] = temp;
            else numArr[i][j] = 0;
        }
    }

    fclose(f);

}

void cleanNoise(int numArr[ROWS][COLS]){

    int avgVal;
    int cmpArr[4];

    for(int i = 0 ; i < ROWS ; i++){
        for(int j = 0; j < COLS ; j++){

            int ind = 0;
            for(int k = 0 ; k < 4 ; k++)
                cmpArr[k] = -1;

            if(j + 1 <= COLS - 1)
                cmpArr[ind++] = numArr[i][j+1];
            if(i - 1 >= 0)
                cmpArr[ind++] = numArr[i-1][j];
            if(j - 1 >= 0)
                cmpArr[ind++] = numArr[i][j-1];
            if(i + 1 <= ROWS - 1)
                cmpArr[ind++] = numArr[i+1][j];

            if((avgVal = makeAvg(numArr[i][j], cmpArr)) == -1)
                continue;
            else
                numArr[i][j] = avgVal;

        }
    }

}

int makeAvg(int num, const int cmpArr[]){

    int check = 0;
    int total = 0;

    for(int i = 0 ; i < 4 ; i++){
        if(cmpArr[i] == -1) continue;
        if(abs(num - cmpArr[i]) > 1) check = 1;
        total += cmpArr[i];
    }

    if(check)
        return (int)(total / 4);
    else
        return -1;

}

void convertNumsToStrs(const int numArr[ROWS][COLS], char strArr[ROWS][COLS+1]){

    const char symbArr[] = {' ', '.', '\'', ':', '~', '*', '=', '?', '%', '#'};

    for(int i = 0 ; i < ROWS ; i++){
        for(int j = 0 ; j < COLS ; j++)
            strArr[i][j] = symbArr[numArr[i][j]];
        strArr[i][COLS] = '\0';
    }

}

void printStrs(const char strArr[ROWS][COLS+1], const char* name){

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

    for(int i = 0 ; i < ROWS ; i++)
        fprintf(f, "%s\n", strArr[i]);

    printf("Output was written in file \"%s\".\n", nameOut);
    fclose(f);

}
