#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

	int side1, side2;
	int mainSide;
	int count = 0;

	for (mainSide = 1; mainSide <= 500; mainSide++) 
		for (side1 = 1 ; side1 <= 500 ; side1++)
			for (side2 = 1; side2 <= 500; side2++) {

				if (side1 * side1 + side2 * side2 == mainSide * mainSide) {

					count++;

					printf("%d) %d^2 + %d^2 = %d^2\n", count, side1, side2, mainSide);

				}

			}

	return 0;

}