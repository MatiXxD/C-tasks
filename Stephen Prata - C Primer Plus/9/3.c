#include <stdio.h>

void print_n_times(char ch, int strSize, int n);

int main(void) {

	char ch;
	int strSize, n;

	printf("Enter char value: ");
	ch = getchar();
	printf("Enter size of string: ");
	scanf_s("%d", &strSize);
	printf("Enter number of repetitions: ");
	scanf_s("%d", &n);

	print_n_times(ch, strSize, n);

	return 0;

}

void print_n_times(char ch, int strSize, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strSize; j++)
			putchar(ch);
		putchar('\n');
	}

}
