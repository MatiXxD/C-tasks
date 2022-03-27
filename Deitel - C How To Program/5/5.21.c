#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void choose(int num);

void squre(void);

void triangle(void);

void rhomb(void);

void circle(void);

int main (void) {

	int num;

	puts("Enter num (1 - squre, 2 - triangle, 3 - rhomb, 4 - circle)");
	scanf_s("%d", &num);
	choose(num);

	return 0;

}

void choose(int num) {

	switch (num) {

	case 1:
		squre();
		break;

	case 2:
		triangle();
		break;

	case 3:
		rhomb();
		break;

	case 4:
		circle();
		break;

	default:
		puts("Entered wrong case. Restart program.");
		break;

	}

}

void squre(void) {

	int side;
	char dignit;

	puts("Enter side");
	scanf_s("%d", &side);
	puts("Enter dignit");
	scanf_s(" %c", &dignit, 1);

	int i;
	int temp = side;

	while (side--) {

		for (i = 1; i <= temp; i++)
			printf("%c", dignit);

		puts("");
	}

}

void triangle(void) {

	int side;
	char dignit;
	int skip, point, i;

	puts("Enter biggest side");
	scanf_s("%d", &side);

	if (!(side % 2)) {

		puts("Wrong side");
		return;

	}

	puts("Enter dignit");
	scanf_s(" %c", &dignit, 1);

	point = 1;
	i = 1;
	skip = (side - 1) / 2;
	while (i <= skip + 1) {

		for (i = 1 ; i <= skip ; i++)
			printf("%s", " ");
		for (i = 1; i <= point; i++)
			printf("%c", dignit);

		puts("");

		skip--;
		point += 2;
		i = 1;

	}

}

void rhomb(void) {

	int diam;
	char dignit;
	int skip, point, save, i;

	puts("Enter diameter");
	scanf_s("%d", &diam);

	if (!(diam % 2)) {

		puts("Wrong side");
		return;

	}

	puts("Enter dignit");
	scanf_s(" %c", &dignit, 1);

	point = 1;
	i = 1;
	skip = (diam - 1) / 2;
	save = skip;

	while (i <= skip + 1) {

		for (i = 1; i <= skip; i++)
			printf("%s", " ");
		for (i = 1; i <= point; i++)
			printf("%c", dignit);

		puts("");

		skip--;
		point += 2;
		i = 1;

	}

	skip += 2;
	point -= 4;
	while (i <= save--) {

		for (i = 1; i <= skip; i++)
			printf("%s", " ");
		for (i = 1; i <= point; i++)
			printf("%c", dignit);

		puts("");

		skip++;
		point -= 2;
		i = 1;
	}

}

void circle(void) {

	int diam;
	char dignit;
	int i, j, k;

	puts("Enter diametre");
	scanf_s("%d", &diam);

	if (diam <= 3) {

		puts("Your diametre is too low.");
		return;

	}

	puts("Enter dignit");
	scanf_s(" %c", &dignit, 1);
	
	i = diam;
	j = 1;
	while (i--) {
		
		k = diam - 2;

		if (j == 1 || j == diam) {

			printf("%s", " ");
			while (k--)
				printf("%c", dignit);

		}

		else {

			printf("%c", dignit);
			while (k--)
				printf("%s", " ");
			printf("%c", dignit);

		}

		puts("");
		j++;

	}

}
