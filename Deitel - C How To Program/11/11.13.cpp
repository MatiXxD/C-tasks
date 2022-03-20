#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SIZE 7

int getNumber(int number[]);
bool checkNextMove(int* strt, int* end, int max);

int main(void) {
    
    int number[NUM_SIZE];
    if (!getNumber(number)) {

        FILE* f;
        f = fopen("numbers.dat", "w");

        char letters[25] = "ABCDEFGHIJKLMNOPRSTUVXYZ";
        int currentLetters[NUM_SIZE] = { 0, 0, 0, 0, 0, 0, 0 };                          //0 means first letter on the phone button.
        do {

            for (int i = 0; i < NUM_SIZE; i++) {

                printf("%d", currentLetters[i]);                                        //If you want to see how enumeration works
                fprintf(f, "%c", letters[number[i] * 3 + currentLetters[i]]);

            }
            
            fprintf(f, "\n");
            puts("");

        } while (checkNextMove(currentLetters, currentLetters + 7, 2));
        
        fclose(f);

    }

    else
        puts("Wrong input");

    return 0; 

} 

int getNumber(int number[]) {

    int num, numPart1, numPart2;
    int i = 0;

    puts("Enter phone number in 222-2222 format (without 0 and 1):");
    scanf_s("%d%*c%d", &numPart1, &numPart2);
    num = numPart2 + numPart1 * 10000;

    do {

        number[NUM_SIZE - 1 - i] = num % 10;
        i++;

    } while (num /= 10);

    for (int i = 0; i < NUM_SIZE; i++)
        if (number[i] == 0 || number[i] == 1)
            return 1;

    return 0;

}

bool checkNextMove(int *strt, int *end, int max) {

    while ((strt != end) && (*strt == max)) {                       

        *strt = 0;                                                  
        strt++;                                                     

    }
 

    if (strt == end)
        return false;

    else {

        (*strt)++;                                                  
        return true;

    }

}
