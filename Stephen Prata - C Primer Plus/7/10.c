#include <stdio.h>
#include <stdbool.h>

#define COEF1 0.15f
#define COEF2 0.28f

int getCategory(void);
float getTax(float sum, int category);

int main(void) {

	float sum;
	int category = getCategory();

	printf("Enter sum: ");
	scanf_s("%f", &sum);
	while ((int)sum != -1) {

		printf("Your tax is %.2f $\n\nEnter new sum (-1 to exit): ", getTax(sum, category));
		scanf_s("%f", &sum);

	}

	return 0;

}

int getCategory(void) {

	int category;

	printf("Enter your category from the list: \n");
	printf("1) Single\n2) Head of family\n"
		   "3) Married, joint household\n"
		   "4) Married, separate household\n");
	scanf_s("%d", &category);
	while (category > 4 || category < 1) {
		printf("Wrong category. Enter again: ");
		scanf_s("%d", &category);
	}

	return category;

}

float getTax(float sum, int category) {

	float max, tax;
	tax = max = 0;

	switch (category) {

	case 1:
		max = 17850;
		break;
	case 2:
		max = 23900;
		break;
	case 3:
		max = 29750;
		break;
	case 4:
		max = 14875;
		break;

	}

	if (sum > max)
		tax = max * COEF1 + (sum - max) * COEF2;
	else
		tax = sum * COEF1;

	return tax;

}
