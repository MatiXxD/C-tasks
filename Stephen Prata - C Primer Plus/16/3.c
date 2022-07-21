#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define PI 2*asinf(1.0f)
#define DEG_TO_RAD PI / 180

inline static void cleanLine(void){
    while(getchar() != '\n')
        continue;
}

typedef struct{
    float r;
    float phi;
}Polar;

typedef struct{
    float x;
    float y;
}Rect;


void getInput(float* r, float* phi);
void convertPolar(Polar* polarCoord, Rect* rectCoord);


int main(int argc, char* argv[]){

    Polar polarCoord;
    Rect rectCoord;
    char option = 'y';

    while(option != 'q'){

        getInput(&polarCoord.r, &polarCoord.phi);
        convertPolar(&polarCoord, &rectCoord);
        printf("Polar system:\nr = %.2f\nphi = %.2f\n",
            polarCoord.r, polarCoord.phi);
        printf("Rectangle system:\nx = %.2f\ny = %.2f\n",
            rectCoord.x, rectCoord.y);

        printf("\nEnter 'q' to stop: ");
        option = tolower(getchar());
        cleanLine();
        
    }

    return 0;

}


void getInput(float* r, float* phi){

    printf("Enter module value (r): ");
    while(scanf("%f", r) != 1 && *r < 0){
        printf("Wrong input. Try again: ");
        cleanLine();
    }
    cleanLine();

    printf("Now enter angle value in degrees (phi): ");
    while(scanf("%f", phi) != 1){
        printf("Wrong input. Try again: ");
        cleanLine();
    }
    cleanLine();

}

void convertPolar(Polar* polarCoord, Rect* rectCoord){

    rectCoord->x = polarCoord->r * cosf(DEG_TO_RAD * polarCoord->phi);
    rectCoord->y = polarCoord->r * sinf(DEG_TO_RAD * polarCoord->phi);

}