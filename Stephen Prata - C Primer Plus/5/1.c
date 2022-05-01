#include <stdio.h>

const int MIN_IN_HOUR = 60;

int main(void) {

	int time;

	printf("Enter time in minutes: ");
	scanf_s("%d", &time);
	while (time > 0) {

		printf("%d minutes is %d hours and %d minutes.\n", time, time / MIN_IN_HOUR, time % MIN_IN_HOUR);
		printf("Enter time in minutes: ");
		scanf_s("%d", &time);

	}

	return 0;

}
