#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

bool even(int number);

int main (void) {

	int number;

	puts("Enter integer numbers");

	while (scanf_s("%d", &number) != EOF)
		printf("%d is %s\n", number, even(number) == 1 ? "even" : "odd");

	return 0;
}

bool even(int number) {

	return !(number % 2);

}
