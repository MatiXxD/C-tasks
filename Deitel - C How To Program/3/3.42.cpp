#include <stdio.h>

int main(void) {

    float radius;
    float p = 3.14159;
    float area, diameter, perimetr;

    puts("Enter radius of the circle");
    scanf_s("%f", &radius);
    
    area = p * radius * radius;
    diameter = 2 * radius;
    perimetr = 2 * p * radius;

    printf("Diameter - %f\n", diameter);
    printf("Area - %f\n", area);
    printf("Perimetr - %f\n", perimetr);

    return 0;
}