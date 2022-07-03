#include <stdio.h>
#include <stdlib.h>

int main() {

    int ch;
    FILE *fp;
    unsigned long count = 0;
    char name[32];

    puts("Enter file name:");
    scanf("%s", name);

    if ((fp = fopen(name, "r")) == NULL){
        printf("Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }

    fclose(fp);
    printf("File %s has %lu characters\n", name, count);

    return 0;

}

