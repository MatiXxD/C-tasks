#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HARM_AVG(X, Y) (2 / ( 1/(X) + 1/(Y)))


inline static void cleanLine(void){
    while(getchar() != '\n')
        continue;
}


int main(void){

    float num1, num2;
    char ch = 'y';

    while(ch != 'q'){
        
        num1 = (float)(rand() & 0xFF);
        num2 = (float)(rand() & 0xFF);
        printf("Harmoniv mean of numbers %f and %f is %f\n",
            num1, num2, HARM_AVG(num1, num2));

        printf("Enter 'q' to stop or anything else to continue: ");
        ch = tolower(getchar());
        cleanLine();

    }

    return 0;

}