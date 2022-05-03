#include <stdio.h>


int main(void) {

	const unsigned SIZE = 26;
	char alphabet[SIZE];

	for (char c = 'a'; c < 'a' + SIZE; c++)
		alphabet[c - 'a'] = c;

	for (int i = 0; i < SIZE; i++)
		printf("%c\n", alphabet[i]);

	return 0;

}
