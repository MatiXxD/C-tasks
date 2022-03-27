#include <stdio.h>

int main(void) {

    int row = 16;
    int col = 8;
    int i = 0;
    int j = 0;
    int pos = 0;

    while (i < col) {

        pos = i;
        j = 0;

        while (j++ < row) {

            if (pos++ % 2)
                printf("%s", "*");

            else
                printf("%s", " ");

        }

        puts("");

        i++;
    }

    return 0;
}