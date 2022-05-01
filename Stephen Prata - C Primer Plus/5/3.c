#include <stdio.h>


int main(void) {

	int days;

	printf("Enter number of days: ");
	scanf_s("%d", &days);
	while (days > 0) {

		printf("%d days is %d weeks and %d days.\n", days, days / 7, days % 7);

		printf("Enter number of days: ");
		scanf_s("%d", &days);

	}

	return 0;

}
