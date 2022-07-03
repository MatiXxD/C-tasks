#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    if(argc < 2){
        puts("Should be at least 1 file name");
        exit(EXIT_FAILURE);
    }

    puts("Files output:");
    for(int i = 0 ; i < argc - 1 ; i++){

        FILE *f = fopen(argv[i+1], "r");
        if(f == NULL){
            printf("Can't open file %s.", argv[i+1]);
            continue;
        }

        char ch;
        while((ch = getc(f)) != EOF)
            putc(ch, stdout);

        fclose(f);

    }

    return 0;

}
