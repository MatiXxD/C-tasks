#include <stdio.h>

void chline(char ch, int start, int end);

int main(void) {

	int start, end;
	char ch;

	printf("Enter char value: ");
	scanf_s("%c", &ch, 1);
	printf("Enter i and j: ");
	scanf_s("%d %d", &start, &end);

	chline(ch, start, end);

	return 0;

}

void chline(char ch, int start, int end) {

	for (int i = 0; i < start - 1; i++)
		putchar(' ');
	for (int i = 0; i <= end - start; i++)
		putchar(ch);
	putchar('\n');

}
