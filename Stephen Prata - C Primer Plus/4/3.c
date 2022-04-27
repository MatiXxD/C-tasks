#include <stdio.h>

int main(void) {

	float num;

	printf("Enter number: ");
	scanf_s("%f", &num);

	printf("%.3f\n%.3e\n", num, num);

    return 0;

}
