#include <stdio.h>

int main(void) {

	int i = 0;
	int ch;

	printf("Start your input (use CTRL+Z or CTRL+D to stop):\n");
	while ((ch = getchar()) != EOF) {

		if (ch < 32 && ch != '\n' && ch != '\t') {
			printf("\"^%c\"-%d\n", ch + 32, ch);
			i = 0;
		}
		else if (ch == '\n') {
			printf("\"\\n\"-%d\n", ch);
			i = 0;
		}
		else if (ch == '\t') {
			printf("\"\\t\"-%d\n", ch);
			i = 0;
		}
		else
			printf("%c-%d", ch, ch);

		putchar((i++ + 1) % 10 ? ' ' : '\n');

		if (i == 10)
			i = 0;

	}

	return 0;

}
