#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {

	double num;
	int power;

	if (argc == 3) {
		sscanf_s(argv[1], "%lf", &num);
		sscanf_s(argv[2], "%d", &power);

		printf("%.2lf^%d = %.2lf\n", num, power, pow(num, power));
	}
	else
		puts("You should enter two value");

	return 0;

}
