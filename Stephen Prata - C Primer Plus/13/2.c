#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    if(argc < 3){
        puts("You have to enter two names.");
        exit(EXIT_FAILURE);
    }

    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");
    if(fin == NULL || fout == NULL){
        puts("Can't open files.");
        exit(EXIT_FAILURE);
    }

    char ch;
    while((ch = getc(fin)) != EOF)
        putc(ch, fout);

    if (fclose(fin) != 0 || fclose(fout) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;

}
