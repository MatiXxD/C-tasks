#include <stdio.h>

int main() {

    FILE* filePtr;
    FILE* tempPtr;
    char fileName[30] = "";

    puts("Enter file's name:");
    scanf_s("%s", fileName, 30);

    fopen_s(&filePtr, fileName, "r+");
    if (filePtr != NULL) {

        tmpfile_s(&tempPtr);
        if (tempPtr != NULL) {

            char c;

            printf("Read from %s :\n", fileName);
            while ((c = getc(filePtr)) != EOF) {

                putchar(c);
                fprintf(tempPtr, "%c ", c);

            }

            rewind(filePtr);
            rewind(tempPtr);

            printf("Replaced on :\n");
            while ((c = getc(tempPtr)) != EOF) {

                putchar(c);
                putc(c, filePtr);

            }

            fclose(tempPtr);

        }
        else
            printf("%s\n", "Temp file wasn't opened.");

        fclose(filePtr);

    }
    else
        printf("File %s wasn't opened.\n", fileName);


    return 0;

}