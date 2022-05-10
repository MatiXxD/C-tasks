#include <stdio.h>

int main(void) {

	int totalChars = 0;
	int totalSpaces = 0;
	int totalNewLines = 0;
	char ch;

	printf("Enter char values (# to stop)\n: ");
	while ((ch = getchar()) != '#') {

		if (ch == ' ')
			totalSpaces++;
		else if (ch == '\n')
			totalNewLines++;
		else
			totalChars++;

	}
	printf("\n%10s%10s%10s\n%10d%10d%10d", "Chars", "Spaces", "New Lines",
		totalChars, totalSpaces, totalNewLines);

	return 0;

}
