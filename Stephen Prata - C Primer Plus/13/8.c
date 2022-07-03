#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchChar(FILE* f, char *argv);

int main(int argc, char* argv[]){

    if(argc < 2){
        puts("You didn't entered any information. At least need enter symbol.");
        exit(EXIT_FAILURE);
    }
    else if(argc == 2){

        puts("You didn't eneterd any files. Stdin will be used instead");
        puts("Enter some text ctrl+z(windows) or ctrl+d(linux) to stop:");

        printf("\n%s was detected %d times in %s.\n", argv[1],
            searchChar(stdin, argv[1]), "stdin");

    }
    else{

        FILE *f;

        for(int i = 0; i < argc - 2 ; i++){

            f = fopen(argv[i+2], "r");
            if(f == NULL){
                printf("File with name %s wasn't open.\n", argv[i+2]);
                continue;
            }

            printf("%s was detected %d times in %s.\n", argv[1],
                searchChar(f, argv[1]), argv[i+2]);

            fclose(f);

        }

    }

    return 0;

}

int searchChar(FILE* f, char *argv){

    int total = 0;
    char ch;
    char strToCmp[2];
    strToCmp[1] = '\0';

    while((ch = getc(f)) != EOF){
        strToCmp[0] = ch;
        if(!strcmp(strToCmp, argv)) total++;
    }

    return total;

}
