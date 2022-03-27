#include <stdio.h>

int main(void) {
   
    int rows, cols, j;
    int i = 0;
    int a;

    puts("Enter rows and cols(from 1 to 20)");
    scanf_s("%d%d", &rows, &cols);

    while (i++ < cols) {                                                // ВЫВОДИТ ПРЯМОУГОЛЬНИК СО СТОРОНАМИ rows И cols

        j = 0;

        while (j++ < rows)
            printf("%s", "*");

        puts("");
    }

    puts("Enter length of the squre side");
    scanf_s("%d", &a);

    i = 0;

    while (i++ < a) {                                                   // ВЫВОДИТ КВАДРАТ СО СТОРОНОЙ a

        j = 0;

        while (j++ < a)
            printf("%s", "*");

        puts("");
    }


    return 0;
} 