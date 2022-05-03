#include <stdio.h>


int main(void) {

	const unsigned SIZE = 6;
	char alphabet[SIZE+1] = "ABCDEF";

	for (int i = 1; i <= SIZE; i++) {
		for (int j = 0; j < i; j++)
			printf("%c", alphabet[SIZE - 1 - j]);
		puts("");
	}

	return 0;

}
