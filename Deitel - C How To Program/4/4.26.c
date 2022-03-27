#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

	int i, accuracy;
	int j = 1;
	float pi = 4;

	printf("Enter accuracy\n");
	scanf_s("%d", &accuracy);

	for (i = 3 ; i <= accuracy ; i += 2) {

		if (!(j % 2))
			pi += 4.0f / i;

		else
			pi -= 4.0f / i;

		j++;

	}

	printf("pi is %f", pi);

	return 0;

}