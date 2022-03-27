#include <stdio.h>
#define SIZE 30

void stringReverse(char[]);

int main()
{
    int loop;
    char strArray[SIZE] = "Print this string backwards.";

    for (loop = 0; loop < SIZE; loop++)
        printf("%c", strArray[loop]);

    printf("\n");
    stringReverse(strArray);
    printf("\n");

    return 0;
}

void stringReverse(char strArray[])
{
    if (strArray[0] == '\0')
        return;

    stringReverse(&strArray[1]);
    printf("%c", strArray[0]);

}