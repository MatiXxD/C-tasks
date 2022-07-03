#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int getOrderNum(const char* name);

int main(void){

    FILE *fp;
    char ch;
    char words[MAX];

    int i = getOrderNum("wordy");
    if ((fp = fopen("wordy", "a+")) == NULL){
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d) %s\n", i++, words);

    puts("File contents:");
    rewind(fp);
    while ((ch = getc(fp)) != EOF)
        putchar(ch);

    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;

}

int getOrderNum(const char* name){

    char ch;
    int order = 0;

    FILE* f = fopen(name, "r");

    if(f == NULL){
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    while((ch = getc(f)) != EOF)
        if(ch == '\n') order++;

    fclose(f);

    return order+1;

}
