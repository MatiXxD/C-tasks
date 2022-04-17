#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE* filePtr;
    FILE* tempFilePtr;
    char fileName[30] = "";

    printf("Enter file name: ");
    scanf_s("%s", fileName, 30);

    fopen_s(&filePtr, fileName, "r+");
    if (filePtr != NULL) {

        tmpfile_s(&tempFilePtr);
        if (tempFilePtr != NULL) {

            fseek(filePtr, 0, SEEK_END);

            char ch;
            int i = 0;
            int size = ftell(filePtr);

            while (i++ < size) {

                fseek(filePtr, -i, SEEK_END);
                ch = getc(filePtr);
                putc(ch, tempFilePtr);

            }

            rewind(filePtr);
            rewind(tempFilePtr);


            printf("Written to file:\n");
            while ((ch = getc(tempFilePtr)) != EOF) {

                putchar(ch);
                putc(ch, filePtr);

            }

            fclose(tempFilePtr);

        }
        else
            puts("Temp file wasn't opened.");

        fclose(filePtr);

    }
    else
        printf("File with name %s wasn't opened.\n", fileName);

    return 0;

}