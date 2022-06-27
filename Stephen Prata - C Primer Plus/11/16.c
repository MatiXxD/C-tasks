#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1024

void readStr(char* str, int size);
void parseStr(char* str, char option);

int main(int argc, char *argv[]) {

	char option = 'p';
	char str[SIZE];

	puts("Start input (EOF to stop):");
	readStr(str, SIZE);

	if (argc >= 2) {
		if (!strcmp(argv[1], "-l") || !strcmp(argv[1], "-L")) option = 'l';
		else if (!strcmp(argv[1], "-u") || !strcmp(argv[1], "-U")) option = 'u';
		else if (strcmp(argv[1], "-p") && strcmp(argv[1], "-P")) puts("Wrong option. Output with option '-p'.");
	}
	puts("\nOutput is:");
	parseStr(str, option);

	return 0;

}

void readStr(char* str, int size) {

	int i = 0;
	char ch;

	while ((ch = getchar()) != EOF && i < size - 1)
		str[i++] = ch;
	str[i] = '\0';

}

void parseStr(char* str, char option) {

	switch (option) {

	case 'p':
		while (*str) putchar(*str++);
		break;
	case 'l':
		while (*str) putchar(tolower(*str++));
		break;
	case 'u':
		while (*str) putchar(toupper(*str++));
		break;

	}

}
