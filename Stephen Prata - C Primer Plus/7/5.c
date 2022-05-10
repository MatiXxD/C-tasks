#include <stdio.h>

int main(void) {

	const unsigned SIZE = 1024;
	char arr[SIZE];
	char ch;
	int i = 0;

	printf("Enter some text:\n");
	while ((ch = getchar()) != '#') {

		switch (ch) {

		case '.':
			arr[i++] = '!';
			break;
		case '!':
			arr[i++] = ch;
			arr[i++] = ch;
			break;
		default:
			arr[i++] = ch;

		}

	}

	printf("Text after parsing:\n");
	for (int j = 0; j < i; j++)
		printf("%c", arr[j]);

	return 0;

}
