#include <stdio.h>

void temperatures(double tem);

int main(void) {

	double tem;

	printf("Enter temperature (in Celsius): ");
	int scanNum = scanf_s("%lf", &tem);
	while (scanNum) {

		temperatures(tem);

		printf("Enter temperature (in Celsius): ");
		scanNum = scanf_s("%lf", &tem);

	}

	return 0;

}

void temperatures(double tem) {

	const double C_TO_K = 273.16;
	const double C_TO_F1 = 9.0 / 5;
	const double C_TO_F2 = 32;

	printf("%.2lf (C) = %.2lf (K) = %.2lf (F).\n",
		tem, tem + C_TO_K, tem * C_TO_F1 + C_TO_F2);
	puts("----------------------------------------");

}
