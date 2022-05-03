#include <stdio.h>


int main(void) {

	char currentCh = 'A' - 1;
	char ch;

	printf("Enter char: ");
	scanf_s("%c", &ch, 1);
	const unsigned SIZE = ch - 'A' + 1;

	for (int i = 1; i <= SIZE; i++) {

		for (int j = 0; j < SIZE - i; j++)
			printf("%c", ' ');
		for (int j = 0; j < i; j++)
			printf("%c", ++currentCh);
		for (int j = 0; j < i - 1; j++)
			printf("%c", --currentCh);

		currentCh = 'A' - 1;
		puts("");

	}

	return 0;

}
