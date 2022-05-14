#include <stdio.h>

int main(void) {

	unsigned count = 0;

	printf("Start your input (use CTRL+Z or CTRL+D to stop):\n");
	while (getchar() != EOF)
		count++;

	printf("You have entered %u symbols.\n", count);

	return 0;

}
