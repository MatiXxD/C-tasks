#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int sekSince12(unsigned int hour, unsigned int min, unsigned int sek);

int check(unsigned int hour, unsigned int min, unsigned int sek);

int main(void) {

	unsigned int hour1, min1, sek1;
	unsigned int hour2, min2, sek2;

	puts("Enter time in hour:min:sek format");
	scanf_s("%d:%d:%d", &hour1, &min1, &sek1);
	if (check(hour1, min1, sek1))
		return 404;
	
	puts("Enter time in hour:min:sek format");
	scanf_s("%d:%d:%d", &hour2, &min2, &sek2);
	if (check(hour2, min2, sek2))
		return 404;

	printf("The interval between %u:%u:%u and %u:%u:%u is %u", hour1, min1, sek1, hour2, min2, sek2,
		(int)fabs((double)sekSince12(hour1, min1, sek1) - (double)sekSince12(hour2, min2, sek2)));

	return 0;

}

 int sekSince12(unsigned int hour, unsigned int min, unsigned int sek) {

	return sek + min * 60 + hour * 60 * 60;

}

int check(unsigned int hour, unsigned int min, unsigned int sek) {

	if (hour > 24 || min > 60 || sek > 60) {

		puts("Entered wrong time");
		return 404;

	}

	return 0;
}