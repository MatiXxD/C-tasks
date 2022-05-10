#include <stdio.h>

int main(void) {

	char ch;
	int count = 0;

	printf("Enter char value (# to stop):\n");
	while ((ch = getchar()) != '#') {
		switch (ch) {

		case '\n':
			printf("\\n-%3d%s", ch, "\nEnter char value (# to stop):\n");
			break;
		case '\t':
			printf("\\t-%3d ", ch);
			break;
		case ' ':
			printf("  -%3d ", ch);
			break;
		default:
			printf(" %c-%3d ", ch, ch);

		}
		if (count++ == 7) {

			putchar('\n');
			count = 0;

		}
	}

	return 0;

}
