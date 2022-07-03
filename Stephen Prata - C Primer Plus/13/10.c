#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

int main(void){

    char ch;
    int pos, out;
    char name[SIZE];

    printf("Enter file name: ");
    scanf("%s", name);

    FILE *f = fopen(name, "r");
    if(f == NULL){
        printf("File %s wasn't opened.\n", name);
        exit(EXIT_FAILURE);
    }

    printf("Enter position to start output (-1 to stop): ");
    out = scanf("%d", &pos);
    while(pos >= 0 && out == 1){

        fseek(f, pos, SEEK_SET);
        while((ch = getc(f)) != '\n')
            putchar(ch);

        printf("\n\nNext pos (-1 to stop): ");
        out = scanf("%d", &pos);

    }

    if (fclose(f) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;

}
