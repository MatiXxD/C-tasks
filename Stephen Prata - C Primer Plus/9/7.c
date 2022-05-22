#include <stdio.h>
#include <ctype.h>

int alphabetNum(char ch);

int main(void) {

	char ch;

	while ((ch = getchar()) != EOF) {

		int check = alphabetNum(ch);
		printf("%c %s letter ", ch, check != -1 ? "is" : "isn't");

		if (check != -1)
			printf("%c is %d in alphabet", ch, check);
		putchar('\n');

	}

	return 0;

}

int alphabetNum(char ch) {

	int num;

	if (isalpha(ch))
		num = tolower(ch) - 97;
	else
		num = -2;

	return num + 1;

}
