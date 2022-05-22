#include <stdio.h>

double power(double num, int pow);

int main(void) {

	int pow;
	double num;

	printf("Enter number and power (q to exit): ");
	while (scanf_s("%lf %d", &num, &pow) == 2) {
		printf("%lf to the %d power is %lf\n", num, pow,
			power(num, pow));
		printf("Enter number and power (q to exit): ");
	}

	return 0;

}

double power(double num, int pow) {

	double res = 1.0;

	if (num == 0.0)
		return 0.0;
	if (pow == 0)
		return 1.0;

	if (pow > 0) {

		if (pow == 1)
			return num;
		else
			return num * power(num, --pow);

	}
	else {

		if (pow == -1)
			return 1.0 / num;
		else
			return (1.0 / num) * power(num, ++pow);

	}

}
