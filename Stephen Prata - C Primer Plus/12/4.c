#include <stdio.h>

int repFunction();

int main(void) {

	int repCount;

	printf("Enter repeat count: ");
	scanf_s("%d", &repCount);

	if (repCount >= 1) {
		while (repCount-- != 1)
			repFunction();
		printf("Function was called %d times.\n", repFunction());
	}
	else
		puts("Repeat count should be positive value.");

}

int repFunction() {

	static repCount = 0;

	return ++repCount;

}
