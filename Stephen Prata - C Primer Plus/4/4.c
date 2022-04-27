#include <stdio.h>

int main(void) {

	float height;
	char name[20];

	printf("Enter your name: ");
	scanf_s("%s", name, 20);
	printf("Enter your height (in cm): ");
	scanf_s("%f", &height);

	printf("%s, your height is %.2f meters.\n", name, height / 100);

    return 0;

}
