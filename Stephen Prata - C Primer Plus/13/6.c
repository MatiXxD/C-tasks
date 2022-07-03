#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

int main() {

    FILE  *in, *out;
    int ch;
    char nameIn[LEN];
    char nameOut[LEN];
    int count = 0;

    printf("Enter file name: ");
    scanf("%s", nameIn);

    if ((in = fopen(nameIn, "r")) == NULL){
        fprintf(stderr, "I couldn't open the file \"%s\"\n", nameIn);
        exit(EXIT_FAILURE);
    }

    strncpy(nameOut, nameIn, LEN - 5);
    nameOut[LEN - 5] = '\0';
    strcat(nameOut, ".red");
    if ((out = fopen(nameOut, "w")) == NULL){
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;

}

