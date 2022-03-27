#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

    int grade, err; 
    unsigned int aCount = 0; 
    unsigned int bCount = 0; 
    unsigned int cCount = 0; 
    unsigned int dCount = 0; 
    unsigned int fCount = 0; 

    puts("Enter the letter grades.");
    puts("Enter the EOF character to end input.");

    
    while ((grade = getchar()) != EOF) {

        err = 0;

        if (grade == 'A' || grade == 'a') {
            aCount++;
            err++;
            continue;
        }


        if (grade == 'B' || grade == 'b') {
            bCount++;
            err++;
            continue;
        }

        if (grade == 'C' || grade == 'c') {
            cCount++;
            err++;
            continue;
        }

        if (grade == 'D' || grade == 'd') {
            dCount++;
            err++;
            continue;
        }

        if (grade == 'F' || grade == 'f') {
            fCount++;
            err++;
            continue;
        }

        if (grade == '\n' || grade == '\t' || grade == ' ') {
            err++;
            continue;
        }

        if (err == 0)
            printf("You have entered the wrong mark!\n");

    } 

    
    puts("\nTotals for each letter grade are:");
    printf("A: %u\n", aCount); 
    printf("B: %u\n", bCount); 
    printf("C: %u\n", cCount); 
    printf("D: %u\n", dCount); 
    printf("F: %u\n", fCount); 

    return 0;

}