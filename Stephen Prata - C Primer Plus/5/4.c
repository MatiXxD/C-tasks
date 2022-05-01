#include <stdio.h>

const float INCH_TO_CM = 2.54f;
const float FT_TO_CM = 30.48f;

int main(void) {

	float cm, inch;
	int ft;

	printf("Enter height in cm: ");
	scanf_s("%f", &cm);
	while (cm > 0) {

		ft = cm / FT_TO_CM;
		inch = (cm - ft * FT_TO_CM) / INCH_TO_CM;
		printf("%.1f cm = %d ft, %.1f inch.\n", cm, ft, inch);

		printf("Enter height in cm: ");
		scanf_s("%f", &cm);

	}

	return 0;

}
