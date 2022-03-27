#include <stdio.h>

#define SIZE 13

void reverseString(char str[], int pos);

int main(void) {

	char str[SIZE] = "SLAVAUKRAINE";

	reverseString(str, SIZE - 2);

	return 0;

}

void reverseString(char str[], int pos) {

	if (pos >= 0) {

		printf("%c", str[pos]);
		reverseString(str, --pos);

	}

	else
		return;

}