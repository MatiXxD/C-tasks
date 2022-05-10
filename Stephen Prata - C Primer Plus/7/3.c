#include <stdio.h>

int main(void) {

	int num;
	int oddCount = 0;
	int evenCount = 0;
	float totalOdd = 0;
	float totalEven = 0;

	printf("Enter integer numeber: ");
	scanf_s("%d", &num);
	while (num != 0) {

		if (num % 2) {
			totalEven += num;
			evenCount++;
		}
		else {
			totalOdd += num;
			oddCount++;
		}

		printf("Enter integer numeber: ");
		scanf_s("%d", &num);

	}
	if(oddCount != 0 && evenCount != 0)
		printf("Odd count = %d\nOdd average = %.2f\nEven count = %d\nEven average = %.2f\n",
			oddCount, totalOdd / oddCount, evenCount, totalEven / evenCount);

	return 0;

}
