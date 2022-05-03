#include <stdio.h>


int main(void) {

	char ch = 'A';

	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j < i; j++)
			printf("%c", ch++);
		puts("");
	}

	return 0;

}
