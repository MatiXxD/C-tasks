#include <stdio.h>
#include <math.h>

int main (void) {

	double number;
	int err = 0;
	
	puts("Enter number (-228 to stop input)");
	scanf_s("%lf", &number);

	while (number != -228) {

		printf("Round number %f is %f", number, floor(number + .5));

		puts("\n\n-----------------------------------\n\n");

		puts("Enter number (-228 to stop input)");
		scanf_s("%lf", &number);

		err++;
	}

	if (err == 0)
		puts("Nothing was entered!");

	return 0;

}