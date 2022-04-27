#include <stdio.h>

int main(void) {

	const float GLTOL = 3.785;
	const float MLTOKM = 1.609;
	float miles, gallons;
	float speedMLG, speedKML;

	printf("Enter number of miles and number of gallons: ");
	scanf_s("%f %f", &miles, &gallons);

	speedMLG = miles / gallons;
	speedKML = (MLTOKM / GLTOL) * speedMLG;
	printf("1) %.1f miles per gallons\n", speedMLG);
	printf("2) %.1f kilometers per liter\n", speedKML);

    return 0;

}
