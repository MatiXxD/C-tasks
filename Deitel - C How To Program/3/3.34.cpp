#include <stdio.h>

int main(void) {
   
    int rows, cols, j;
    int i = 0;
    int a;

    puts("Enter rows and cols(from 1 to 20)");
    scanf_s("%d%d", &rows, &cols);

    while (i < cols) {                                                // ВЫВОДИТ ПОЛЫЙ ПРЯМОУГОЛЬНИК СО СТОРОНАМИ rows И cols
       
        j = 0;

        if (i == 0)
            while (j++ < rows)
                printf("%s", "*");

        else if (i == cols - 1)
            while (j++ < rows)
                printf("%s", "*");

        else 
            while(j < rows){
                
                if (j == 0)
                    printf("%s", "*");

                else if (j == rows - 1)
                    printf("%s", "*");

                else
                    printf("%s", " ");

                j++;

            }

        puts("");
        i++;
    }

    puts("Enter length of the squre side");
    scanf_s("%d", &a);

    i = 0;

    while (i++ < a) {                                                   // ВЫВОДИТ ПОЛЫЙ КВАДРАТ СО СТОРОНОЙ a

        j = 0;

        if (i == 1) 
            while (j++ < a) 
                printf("%s", "*");

        else if (i == a)
            while (j++ < a)
                printf("%s", "*");

        else
            while (j++ < a) {

                if (j == 1)
                    printf("%s", "*");
                
                else if (j == a)
                    printf("%s", "*");

                else
                    printf("%s", " ");

            }

        puts("");
    }


    return 0;
} 