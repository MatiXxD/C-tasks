#include <stdio.h>
#include <string.h>

int main(void) {

	const int SIZE = 256;
	int i = 0;
	char str[SIZE] = "";
	char ch;

	printf("Enter your string: ");
	do {
		scanf_s("%c", &ch, 1);
		str[i++] = ch;

	} while (ch != '\n');
	str[i-1] = '\0';                                                               //Change \n to \0

	puts("Reversed string: ");
	for (int j = strlen(str) - 1; j >= 0; j--)
		printf("%c", str[j]);

	return 0;

}
