#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void timer(double time);

int main(void){

    double time;
    
    printf("Enter time value: ");
    scanf("%lf", &time);

    timer(time);

    return 0;

}

void timer(double time){

    clock_t start = clock();
    double dt = abs(clock() - start);
    
    while(dt / CLOCKS_PER_SEC < time){
        dt = abs(clock() - start);
    }

}