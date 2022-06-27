#include <stdio.h>
#include <string.h>

#define SIZE 100
#define LIM 10

int getOption();
void cleanBuffer();
char* s_gets(char* str, int size);
int inputStr(char(*strArr)[SIZE]);
void printStrs(const char(*strArr)[SIZE], int count);
void sortByValue(char(*strArr)[SIZE], int count);
void sortByStrLen(char(*strArr)[SIZE], int count);
int wordLen(char* str);
void sortByWordLen(char(*strArr)[SIZE], int count);

int main(void) {

    int option;
    char strArr[LIM][SIZE];

    int count = inputStr(strArr);
    do {
        option = getOption();
        if (option == 5) {
            puts("End!");
            break;
        }

        switch (option) {
        case 1:
            printStrs(strArr, count);
            break;
        case 2:
            sortByValue(strArr, count);
            break;
        case 3:
            sortByStrLen(strArr, count);
            break;
        case 4:
            sortByWordLen(strArr, count);
            break;
        default:
            puts("Wrong input.");
        }

    } while (1);

    return 0;

}

int getOption() {

    int option;

    puts("\nWhat you want to do with your strings?");
    printf("%s\n%s\n%s\n%s\n%s\n", "1) Print strings",
        "2) Sort strings (by value)", "3) Sort strings (by length of string)",
        "4) Sort strings (by length of word)", "5) Exit");

    scanf_s("%d", &option);
    cleanBuffer();

    return option;

}

void cleanBuffer() {

    while (getchar() != '\n') continue;

}

char* s_gets(char* str, int size) {

    char* retVal = fgets(str, size, stdin);
    if (retVal) {

        while (*str != '\n' && *str != '\0')
            str++;

        if (*str == '\n')
            *str = '\0';
        else
            cleanBuffer();

    }

    return retVal;

}

int inputStr(char(*strArr)[SIZE]) {

    int i = 0;
    int count = 0;

    puts("Enter string (ctrl + z to stop):");
    char* retVal = s_gets(strArr[i++], SIZE);
    if (retVal) {
        while (++count < LIM && retVal) {
            puts("Enter string (ctrl + z to stop):");
            retVal = s_gets(strArr[i++], SIZE);
        }
    }

    if (retVal)
        return count;
    else
        return count - 1;

}

void printStrs(const char(*strArr)[SIZE], int count) {

    puts("\n\nStrings output:");
    for (int i = 0; i < count; i++) {
        for (int j = 0; strArr[i][j]; j++)
            putchar(strArr[i][j]);
        putchar('\n');
    }

    putchar('\n');

}

void sortByValue(char(*strArr)[SIZE], int count) {

    char* ptrArr[LIM];
    for (int i = 0; i < count; i++)
        ptrArr[i] = strArr[i];

    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (strcmp(ptrArr[i], ptrArr[j]) > 0) {
                char* tempPtr = ptrArr[i];
                ptrArr[i] = ptrArr[j];
                ptrArr[j] = tempPtr;
            }

    puts("\nSorted by value strings:");
    for (int i = 0; i < count; i++)
        printf("%s\n", ptrArr[i]);

}

void sortByStrLen(char(*strArr)[SIZE], int count) {

    char* ptrArr[LIM];
    for (int i = 0; i < count; i++)
        ptrArr[i] = strArr[i];

    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (strlen(ptrArr[i]) > strlen(ptrArr[j])) {
                char* tempPtr = ptrArr[i];
                ptrArr[i] = ptrArr[j];
                ptrArr[j] = tempPtr;
            }

    puts("\nSorted by strings length strings:");
    for (int i = 0; i < count; i++)
        printf("%s\n", ptrArr[i]);

}

int wordLen(char* str) {

    int count = 0;

    while (*str != ' ' && *str != '\t' && *str) {
        count++;
        str++;
    }

    return count;

}

void sortByWordLen(char(*strArr)[SIZE], int count) {

    char* ptrArr[LIM];
    for (int i = 0; i < count; i++)
        ptrArr[i] = strArr[i];

    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (wordLen(ptrArr[i]) > wordLen(ptrArr[j])) {
                char* tempPtr = ptrArr[i];
                ptrArr[i] = ptrArr[j];
                ptrArr[j] = tempPtr;
            }

    puts("\nSorted by word length strings:");
    for (int i = 0; i < count; i++)
        printf("%s\n", ptrArr[i]);

}
